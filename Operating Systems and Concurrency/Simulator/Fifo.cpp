#include "Fifo.h"
#include<iostream>
#include<random>
#include <queue>
#include<vector>
using namespace std;

double simulater::random(double low, double high){
	static random_device rd;
	static mt19937 eng(rd());
	uniform_real_distribution<double> dist(low, high);
	return dist(eng);
}
int simulater::random1(int low, int high){
	static random_device rd;
	static mt19937 eng(rd());
	uniform_int_distribution<int> dist(low, high);
	return dist(eng);
}
task simulater::get_CPU_task(){
	int numparts = random1(2, 5);
	int io_device_num;
	int page_num;
	double dur = random(2.0, 15.0);

	task i;
	duriation += dur;
	io_device_num = random1(0, mem->getsize() - 1);
	i.TI.emplace_back(CPU, dur, io_device_num);
	for (int j = 0; j < numparts; ++j){
		dur = random(1.0, 7.0);
		io_device_num = random1(0, Num_IO - 1);
		i.TI.emplace_back(IO, dur, io_device_num);
		dur = random(7.0, 15);
		duriation += dur;
		io_device_num = random1(0, mem->getsize() - 1);
		i.TI.emplace_back(CPU, dur, io_device_num);
	}
	return i;

}
task simulater::get_Io_task(){
	int numparts = random1(2, 5);
	double dur = random(2.0, 15.0);
	int io_device_num;
	task i;
	duriation += dur;
	io_device_num = random1(0, mem->getsize() - 1);
	i.TI.emplace_back(CPU, dur, io_device_num);
	for (int j = 0; j < numparts; ++j){
		dur = random(7.0, 15.0);
		io_device_num = random1(0, Num_IO - 1);
		i.TI.emplace_back(IO, dur, io_device_num);
		dur = random(0.0, 7.0);
		duriation += dur;
		io_device_num = random1(0, mem->getsize() - 1);
		i.TI.emplace_back(CPU, dur, io_device_num);
	}
	return i;
}
void simulater::creat_tasks(){
	numTasks = random1(1, 1);
	for (int i = 0, c_time = 0; i < numTasks; ++i){
		double rtasktypes = random(0.0, 1.0);
		if (rtasktypes < Task_mix){
			take.push_back(get_CPU_task());
		}
		else{
			take.push_back(get_Io_task());

		}
	}
}
void simulater::create_event(Event E){
	eventCount++;
	current_time = E.time_event;
	E.t.creationTime = current_time;
	if (E.t.TI[0].TP == taskType::CPU){
		if (Num_CPU>0){
			Event temp(E.t, mem->getpage(E.t.TI[0].io_device) + current_time + E.t.TI[0].duration + context_switch, Event::event_type::cpu_end, true);
			Pq_event.push(temp);
			Num_CPU--;
		}
		else{
			cpu_queue.push(E.t);
		}
	}
	else if (E.t.TI[0].TP == taskType::IO)
	{
		if (io_bool[E.t.TI[0].io_device]){
			Event temp(E.t, current_time + E.t.TI[0].duration + context_switch, Event::event_type::Io_end, true);
			Pq_event.push(temp);
			io_bool[E.t.TI[0].io_device] = false;
		}
		else{
			io_queue[E.t.TI[0].io_device].push(E.t);
		}
	}
	else{
		cout << "bad!" << endl;
	}
}
void simulater::cpu_end(Event E){
	current_time = E.time_event;
	E.t.TI.erase(E.t.TI.begin());
	Num_CPU++;
	if (E.t.TI.empty()){
		cout << "task empty" << endl;
		cout << "duriation: " << (current_time - E.processCreation) << endl;
		Laten_sum += current_time - E.processCreation;

	}
	else{
		if (E.t.TI[0].TP == taskType::IO){
			if (io_bool[E.t.TI[0].io_device]){
				Event temp(E.t, current_time + E.t.TI[0].duration + context_switch, Event::event_type::Io_end, E.isFirstIO, E.processCreation);
				Pq_event.push(temp);
				io_bool[E.t.TI[0].io_device] = false;
			}
			else{
				io_queue[E.t.TI[0].io_device].push(E.t);
			}
		}
	}
	if (Num_CPU != 0 && !cpu_queue.empty()){
		task r = cpu_queue.front();
		cpu_queue.pop();
		Event b(r, current_time + r.TI[0].duration + context_switch, Event::event_type::cpu_end);
		Pq_event.push(b);
	}
	else{
		cout << "done for cup!" << endl;
	}
}
void simulater::io_end(Event E){
	int device = E.t.TI[0].io_device;
	current_time = E.time_event;
	if (E.isFirstIO) {
		responseSum += current_time - E.processCreation;
		E.isFirstIO = false;
	}
	io_bool[device] = true;
	E.t.TI.erase(E.t.TI.begin());
	if (E.t.TI.empty()){
		cout << "task empty!" << endl;
		cout << "duriation: " << current_time - E.t.creationTime << endl;
	}
	else{
		if (Num_CPU>0){
			Event temp(E.t, mem->getpage(E.t.TI[0].io_device) + current_time + E.t.TI[0].duration + context_switch, Event::event_type::cpu_end, E.isFirstIO, E.processCreation);
			Pq_event.push(temp);
			Num_CPU--;
		}
		else{
			cpu_queue.push(E.t);
		}
	}
	if (io_bool[device]){
		if (!io_queue[device].empty()){
			task g = io_queue[device].front();
			io_queue[device].pop();
			Event c(g, current_time + g.TI[0].duration + context_switch, Event::event_type::Io_end, E.processCreation);
			Pq_event.push(c);
			io_bool[device] = false;
		}
		else{
			cout << "io_queue is empty!" << endl;
		}
	}
	else{
		cout << "Io_device is done!" << endl;
	}
}
void simulater::simulator(){
	for (int i = 0; i < take.size(); i++){
		Event temp(take[i], i*Task_frequency, Event::event_type::creat);
		Pq_event.push(temp);
	}
	while (!Pq_event.empty()){
		Event t = Pq_event.top(); Pq_event.pop();
		int current_time = t.time_event;
		switch (t.e_type)
		{
		case Event::event_type::creat: create_event(t); break;
		case Event::event_type::cpu_end: cpu_end(t); break;
		case Event::event_type::Io_end: io_end(t); break;
		default:
			break;
		}
	}
	throughPut = numTasks / current_time;
	Efficiency = duriation / (current_time*Num_CPU);
}

///////memory////////////////////////////////////////////////////////////////

bool Fifo::insert(int page){
	for (int i = 0; i < hold_page.size() - 1; ++i){
		if (hold_page[i] == page){
			return false;
		}
	}
	hold_page[cur] = page;
	cur++;
	if (cur == Size_of_cache){
		cur = 0;
	}
	return true;
}
int Fifo::getpage(int page){
	if (insert(page)){
		total_cache_miss++;
		return Cache_miss_penalty;
		
	}
	return 0;
}
int second_Chance::getpage(int page){
	
	for (int i = 0; i < hold_page.size() - 1; ++i){
		if (hold_page[i] == page){
			check_mark[i] = true;
			return 0;
		}
	}
	while (check_mark[cur] == true){
		check_mark[cur] = false;
		cur++;
		if (cur == Size_of_cache){
			cur = 0;
		}
	}

	hold_page[cur] = page;
	check_mark[cur] = false;
	cur++;
	if (cur == Size_of_cache){
		cur = 0;
	}
	total_cache_miss++;
	return Cache_miss_penalty;
}
int Most_Recently::getpage(int page){

	for (int i = 0; i < hold_page.size() - 1; ++i){
		if (hold_page[i] == page){
			if (filled == true){
				cur = i;
			}
			return 0;
		}
	}
	hold_page[cur] = page;
	if (filled == false){
		cur++;
	}
	if (cur == Size_of_cache){
		filled = true;
		cur = 0;
	}
	total_cache_miss++;
	return Cache_miss_penalty;
}
int Last_Recently::getpage(int page){
	for (int i = 0; i < hold_page.size() - 1; ++i){
		if (hold_page[i] == page){
			return 0;
		}
	}
	int num_count = 0;
	int index = 0;
	for (int i = 0; i < Size_of_cache; i++){
		if (count_num[i] < count_num[index]){
			index = i;

		}
		if (count_num[i] > count_num[num_count]){
			num_count = i;
		}
	}
	hold_page[index] = page;
	count_num[index] = count_num[num_count] + 1;
	hold_page[cur] = page;
	total_cache_miss++;
	return Cache_miss_penalty;
}

///////roundRobin//////////////////////////////////////////////////////////////////////

double roundRobin::random(double low, double high){
	static random_device rd;
	static mt19937 eng(rd());
	uniform_real_distribution<double> dist(low, high);
	return dist(eng);
}
int roundRobin::random1(int low, int high){
	static random_device rd;
	static mt19937 eng(rd());
	uniform_int_distribution<int> dist(low, high);
	return dist(eng);
}
task roundRobin::get_CPU_task(){
	int numparts = random1(2, 5);
	int io_device_num;
	int page_num;
	double dur = random(2.0, 15.0);

	task i;
	duriation += dur;
	io_device_num = random1(0, mem->getsize() - 1);
	i.TI.emplace_back(CPU, dur, io_device_num);
	for (int j = 0; j < numparts; ++j){
		dur = random(1.0, 7.0);
		io_device_num = random1(0, Num_IO - 1);
		i.TI.emplace_back(IO, dur, io_device_num);
		dur = random(7.0, 15);
		duriation += dur;
		io_device_num = random1(0, mem->getsize() - 1);
		i.TI.emplace_back(CPU, dur, io_device_num);
	}
	return i;

}
task roundRobin::get_Io_task(){
	int numparts = random1(2, 5);
	double dur = random(2.0, 15.0);
	int io_device_num;
	task i;
	duriation += dur;
	io_device_num = random1(0, mem->getsize() - 1);
	i.TI.emplace_back(CPU, dur, io_device_num);
	for (int j = 0; j < numparts; ++j){
		dur = random(7.0, 15.0);
		io_device_num = random1(0, Num_IO - 1);
		i.TI.emplace_back(IO, dur, io_device_num);
		dur = random(0.0, 7.0);
		duriation += dur;
		io_device_num = random1(0, mem->getsize() - 1);
		i.TI.emplace_back(CPU, dur, io_device_num);
	}
	return i;
}
void roundRobin::creat_tasks(){
	numTasks = random1(1, 1);
	for (int i = 0, c_time = 0; i < numTasks; ++i){
		double rtasktypes = random(0.0, 1.0);
		if (rtasktypes < Task_mix){
			take.push_back(get_CPU_task());
		}
		else{
			take.push_back(get_Io_task());

		}
	}
}
void roundRobin::create_event(Event E){
	eventCount++;
	current_time = E.time_event;
	E.t.creationTime = current_time;
	if (E.t.TI[0].TP == taskType::CPU){
		if (Num_CPU>0){
			Event temp(E.t, mem->getpage(E.t.TI[0].io_device) + current_time + E.t.TI[0].duration + context_switch, Event::event_type::cpu_end, true);
			Pq_event.push(temp);
			Num_CPU--;
		}
		else{
			cpu_queue.push(E.t);
		}
	}
	else if (E.t.TI[0].TP == taskType::IO)
	{
		if (io_bool[E.t.TI[0].io_device]){
			Event temp(E.t, current_time + E.t.TI[0].duration + context_switch, Event::event_type::Io_end, true);
			Pq_event.push(temp);
			io_bool[E.t.TI[0].io_device] = false;
		}
		else{
			io_queue[E.t.TI[0].io_device].push(E.t);
		}
	}
	else{
		cout << "bad!" << endl;
	}
}
void roundRobin::cpu_end(Event E){
	current_time = E.time_event;
	E.t.TI.erase(E.t.TI.begin());
	Num_CPU++;
	if (E.t.TI.empty()){
		cout << "task empty" << endl;
		cout << "duriation: " << (current_time - E.processCreation) << endl;
		Laten_sum += current_time - E.processCreation;

	}
	else{
		if (E.t.TI[0].TP == taskType::IO){
		
			if (io_bool[E.t.TI[0].io_device]){
				Event temp(E.t, current_time + E.t.TI[0].duration + context_switch, Event::event_type::Io_end, E.isFirstIO, E.processCreation);
				Pq_event.push(temp);
				io_bool[E.t.TI[0].io_device] = false;
			}

			else{
				io_queue[E.t.TI[0].io_device].push(E.t);
			}

		}
		else{
			if (Num_CPU>0){

				if (E.t.TI[0].duration > time_limit){
					E.t.TI[0].duration -= time_limit;
					Event temp(E.t, mem->getpage(E.t.TI[0].io_device) + current_time + time_limit + context_switch, Event::event_type::cpu_end, E.isFirstIO, E.processCreation);
					Pq_event.push(temp);
				}
				else
				{
					Event temp(E.t, mem->getpage(E.t.TI[0].io_device) + current_time + E.t.TI[0].duration + context_switch, Event::event_type::cpu_end, E.isFirstIO, E.processCreation);
					Pq_event.push(temp);
				}
				Num_CPU--;
			}
			else{
				cpu_queue.push(E.t);
			}
		}
	}
	if (Num_CPU != 0 && !cpu_queue.empty()){
		task r = cpu_queue.front();
		cpu_queue.pop();
		Event b(r, current_time + r.TI[0].duration + context_switch, Event::event_type::cpu_end);
		Pq_event.push(b);
	}
	else{
		cout << "done for cup!" << endl;
	}
}
void roundRobin::io_end(Event E){
	int device = E.t.TI[0].io_device;
	current_time = E.time_event;
	if (E.isFirstIO) {
		responseSum += current_time - E.processCreation;
		E.isFirstIO = false;
	}
	io_bool[device] = true;
	E.t.TI.erase(E.t.TI.begin());
	if (E.t.TI.empty()){
		cout << "task empty!" << endl;
		cout << "duriation: " << current_time - E.t.creationTime << endl;
	}
	else{
		if (Num_CPU>0){

			if (E.t.TI[0].duration > time_limit){
				E.t.TI[0].duration -= time_limit;
				Event temp(E.t, mem->getpage(E.t.TI[0].io_device) + current_time + time_limit + context_switch, Event::event_type::cpu_end, E.isFirstIO, E.processCreation);
				Pq_event.push(temp);
			}
			else
			{
				Event temp(E.t, mem->getpage(E.t.TI[0].io_device) + current_time + E.t.TI[0].duration + context_switch, Event::event_type::cpu_end, E.isFirstIO, E.processCreation);
				Pq_event.push(temp);
			}
			Num_CPU--;
		}
		else{
			cpu_queue.push(E.t);
		}
	}
	if (io_bool[device]){
		if (!io_queue[device].empty()){
			task g = io_queue[device].front();
			io_queue[device].pop();
			Event c(g, current_time + g.TI[0].duration + context_switch, Event::event_type::Io_end, E.processCreation);
			Pq_event.push(c);
			io_bool[device] = false;
		}
		else{
			cout << "io_queue is empty!" << endl;
		}
	}
	else{
		cout << "Io_device is done!" << endl;
	}
}
void roundRobin::simulator(){
	for (int i = 0; i < take.size(); i++){
		Event temp(take[i], i*Task_frequency, Event::event_type::creat);
		Pq_event.push(temp);
	}
	while (!Pq_event.empty()){
		Event t = Pq_event.top(); Pq_event.pop();
		int current_time = t.time_event;
		switch (t.e_type)
		{
		case Event::event_type::creat: create_event(t); break;
		case Event::event_type::cpu_end: cpu_end(t); break;
		case Event::event_type::Io_end: io_end(t); break;
		default:
			break;
		}
	}
	throughPut = numTasks / current_time;
	Efficiency = duriation / (current_time*Num_CPU);
}
//////Shortest job first////////////////////////////////////////////////////////////////

bool operator < (const ShortestFirst::MyEvent & lhs, const ShortestFirst::MyEvent & rhs) {
	return lhs.t.duration < rhs.t.duration;
}
double ShortestFirst::random(double low, double high){
	static random_device rd;
	static mt19937 eng(rd());
	uniform_real_distribution<double> dist(low, high);
	return dist(eng);
}
int ShortestFirst::random1(int low, int high){
	static random_device rd;
	static mt19937 eng(rd());
	uniform_int_distribution<int> dist(low, high);
	return dist(eng);
}
task ShortestFirst::get_CPU_task(){
	int numparts = random1(2, 5);
	int io_device_num;
	int page_num;
	double dur = random(2.0, 15.0);

	task i;
	duriation += dur;
	io_device_num = random1(0, mem->getsize() - 1);
	i.TI.emplace_back(CPU, dur, io_device_num);
	for (int j = 0; j < numparts; ++j){
		dur = random(1.0, 7.0);
		io_device_num = random1(0, Num_IO - 1);
		i.TI.emplace_back(IO, dur, io_device_num);
		dur = random(7.0, 15);
		duriation += dur;
		io_device_num = random1(0, mem->getsize() - 1);
		i.TI.emplace_back(CPU, dur, io_device_num);
	}
	return i;

}
task ShortestFirst::get_Io_task(){
	int numparts = random1(2, 5);
	double dur = random(2.0, 15.0);
	int io_device_num;
	task i;
	duriation += dur;
	io_device_num = random1(0, mem->getsize() - 1);
	i.TI.emplace_back(CPU, dur, io_device_num);
	for (int j = 0; j < numparts; ++j){
		dur = random(7.0, 15.0);
		io_device_num = random1(0, Num_IO - 1);
		i.TI.emplace_back(IO, dur, io_device_num);
		dur = random(0.0, 7.0);
		duriation += dur;
		io_device_num = random1(0, mem->getsize() - 1);
		i.TI.emplace_back(CPU, dur, io_device_num);
	}
	return i;
}
void ShortestFirst::creat_tasks(){
	numTasks = random1(1, 1);
	for (int i = 0, c_time = 0; i < numTasks; ++i){
		double rtasktypes = random(0.0, 1.0);
		if (rtasktypes < Task_mix){
			take.push_back(get_CPU_task());
		}
		else{
			take.push_back(get_Io_task());

		}
	}
}
void ShortestFirst::create_event(MyEvent E){
	eventCount++;
	current_time = E.time_event;
	E.t.creationTime = current_time;
	if (E.t.TI[0].TP == taskType::CPU){
		if (Num_CPU>0){
			MyEvent temp(E.t, mem->getpage(E.t.TI[0].io_device) + current_time + E.t.TI[0].duration + context_switch, MyEvent::event_type::cpu_end, true);
			Pq_event.push(temp);
			Num_CPU--;
		}
		else{
			cpu_queue.push(E.t);
		}
	}
	else if (E.t.TI[0].TP == taskType::IO)
	{
		if (io_bool[E.t.TI[0].io_device]){
			MyEvent temp(E.t, current_time + E.t.TI[0].duration + context_switch, MyEvent::event_type::Io_end, true);
			Pq_event.push(temp);
			io_bool[E.t.TI[0].io_device] = false;
		}
		else{
			io_queue[E.t.TI[0].io_device].push(E.t);
		}
	}
	else{
		cout << "bad!" << endl;
	}
}
void ShortestFirst::cpu_end(MyEvent E){
	current_time = E.time_event;
	E.t.TI.erase(E.t.TI.begin());
	Num_CPU++;
	if (E.t.TI.empty()){
		cout << "task empty" << endl;
		cout << "duriation: " << (current_time - E.processCreation) << endl;
		Laten_sum += current_time - E.processCreation;

	}
	else{
		if (E.t.TI[0].TP == taskType::IO){
			if (io_bool[E.t.TI[0].io_device]){
				MyEvent temp(E.t, current_time + E.t.TI[0].duration + context_switch, MyEvent::event_type::Io_end, E.isFirstIO, E.processCreation);
				Pq_event.push(temp);
				io_bool[E.t.TI[0].io_device] = false;
			}
			else{
				io_queue[E.t.TI[0].io_device].push(E.t);
			}
		}
	}
	if (Num_CPU != 0 && !cpu_queue.empty()){
		task r = cpu_queue.front();
		cpu_queue.pop();
		MyEvent b(r, current_time + r.TI[0].duration + context_switch, MyEvent::event_type::cpu_end);
		Pq_event.push(b);
	}
	else{
		cout << "done for cup!" << endl;
	}
}
void ShortestFirst::io_end(MyEvent E){
	int device = E.t.TI[0].io_device;
	current_time = E.time_event;
	if (E.isFirstIO) {
		responseSum += current_time - E.processCreation;
		E.isFirstIO = false;
	}
	io_bool[device] = true;
	E.t.TI.erase(E.t.TI.begin());
	if (E.t.TI.empty()){
		cout << "task empty!" << endl;
		cout << "duriation: " << current_time - E.t.creationTime << endl;
	}
	else{
		if (Num_CPU>0){
			MyEvent temp(E.t, mem->getpage(E.t.TI[0].io_device) + current_time + E.t.TI[0].duration + context_switch, MyEvent::event_type::cpu_end, E.isFirstIO, E.processCreation);
			Pq_event.push(temp);
			Num_CPU--;
		}
		else{
			cpu_queue.push(E.t);
		}
	}
	if (io_bool[device]){
		if (!io_queue[device].empty()){
			task g = io_queue[device].front();
			io_queue[device].pop();
			MyEvent c(g, current_time + g.TI[0].duration + context_switch, MyEvent::event_type::Io_end, E.processCreation);
			Pq_event.push(c);
			io_bool[device] = false;
		}
		else{
			cout << "io_queue is empty!" << endl;
		}
	}
	else{
		cout << "Io_device is done!" << endl;
	}
}
void ShortestFirst::simulator(){
	for (int i = 0; i < take.size(); i++){
		MyEvent temp(take[i], i*Task_frequency, MyEvent::event_type::creat);
		Pq_event.push(temp);
	}
	while (!Pq_event.empty()){
		MyEvent t = Pq_event.top(); Pq_event.pop();
		int current_time = t.time_event;
		switch (t.e_type)
		{
		case MyEvent::event_type::creat: create_event(t); break;
		case MyEvent::event_type::cpu_end: cpu_end(t); break;
		case MyEvent::event_type::Io_end: io_end(t); break;
		default:
			break;
		}
	}
	throughPut = numTasks / current_time;
	Efficiency = duriation / (current_time*Num_CPU);
}


//////Approximate Shortest job first////////////////////////////////////////////////////////
bool operator < (const Approximate::MyEvent & lhs, const Approximate::MyEvent & rhs) {
	return lhs.t.duration < rhs.t.duration;
}
double Approximate::random(double low, double high){
	static random_device rd;
	static mt19937 eng(rd());
	uniform_real_distribution<double> dist(low, high);
	return dist(eng);
}
int Approximate::random1(int low, int high){
	static random_device rd;
	static mt19937 eng(rd());
	uniform_int_distribution<int> dist(low, high);
	return dist(eng);
}
task Approximate::get_CPU_task(){
	int numparts = random1(2, 5);
	int io_device_num;
	int page_num;
	double dur = random(2.0, 15.0);
	double approx_dur = random(2.0, dur);
	task i;
	duriation += approx_dur;
	io_device_num = random1(0, mem->getsize() - 1);
	i.TI.emplace_back(CPU, approx_dur, io_device_num);
	for (int j = 0; j < numparts; ++j){
		approx_dur = random(1.0, 7.0);
		io_device_num = random1(0, Num_IO - 1);
		i.TI.emplace_back(IO, approx_dur, io_device_num);
		approx_dur = random(7.0, 15);
		duriation += approx_dur;
		io_device_num = random1(0, mem->getsize() - 1);
		i.TI.emplace_back(CPU, approx_dur, io_device_num);
	}
	return i;

}
task Approximate::get_Io_task(){
	int numparts = random1(2, 5);
	double dur = random(2.0, 15.0);
	double approx_dur = random(2.0, dur);
	int io_device_num;
	task i;
	duriation += approx_dur;
	io_device_num = random1(0, mem->getsize() - 1);
	i.TI.emplace_back(CPU, approx_dur, io_device_num);
	for (int j = 0; j < numparts; ++j){
		approx_dur = random(7.0, 15.0);
		io_device_num = random1(0, Num_IO - 1);
		i.TI.emplace_back(IO, approx_dur, io_device_num);
		approx_dur = random(0.0, 7.0);
		duriation += approx_dur;
		io_device_num = random1(0, mem->getsize() - 1);
		i.TI.emplace_back(CPU, approx_dur, io_device_num);
	}
	return i;
}
void Approximate::creat_tasks(){
	numTasks = random1(1, 1);
	for (int i = 0, c_time = 0; i < numTasks; ++i){
		double rtasktypes = random(0.0, 1.0);
		if (rtasktypes < Task_mix){
			take.push_back(get_CPU_task());
		}
		else{
			take.push_back(get_Io_task());

		}
	}
}
void Approximate::create_event(MyEvent E){
	eventCount++;
	current_time = E.time_event;
	E.t.creationTime = current_time;
	if (E.t.TI[0].TP == taskType::CPU){
		if (Num_CPU>0){
			MyEvent temp(E.t, mem->getpage(E.t.TI[0].io_device) + current_time + E.t.TI[0].duration + context_switch, MyEvent::event_type::cpu_end, true);
			Pq_event.push(temp);
			Num_CPU--;
		}
		else{
			cpu_queue.push(E.t);
		}
	}
	else if (E.t.TI[0].TP == taskType::IO)
	{
		if (io_bool[E.t.TI[0].io_device]){
			MyEvent temp(E.t, current_time + E.t.TI[0].duration + context_switch, MyEvent::event_type::Io_end, true);
			Pq_event.push(temp);
			io_bool[E.t.TI[0].io_device] = false;
		}
		else{
			io_queue[E.t.TI[0].io_device].push(E.t);
		}
	}
	else{
		cout << "bad!" << endl;
	}
}
void Approximate::cpu_end(MyEvent E){
	current_time = E.time_event;
	E.t.TI.erase(E.t.TI.begin());
	Num_CPU++;
	if (E.t.TI.empty()){
		cout << "task empty" << endl;
		cout << "duriation: " << (current_time - E.processCreation) << endl;
		Laten_sum += current_time - E.processCreation;

	}
	else{
		if (E.t.TI[0].TP == taskType::IO){
			if (io_bool[E.t.TI[0].io_device]){
				MyEvent temp(E.t, current_time + E.t.TI[0].duration + context_switch, MyEvent::event_type::Io_end, E.isFirstIO, E.processCreation);
				Pq_event.push(temp);
				io_bool[E.t.TI[0].io_device] = false;
			}
			else{
				io_queue[E.t.TI[0].io_device].push(E.t);
			}
		}
	}
	if (Num_CPU != 0 && !cpu_queue.empty()){
		task r = cpu_queue.front();
		cpu_queue.pop();
		MyEvent b(r, current_time + r.TI[0].duration + context_switch, MyEvent::event_type::cpu_end);
		Pq_event.push(b);
	}
	else{
		cout << "done for cup!" << endl;
	}
}
void Approximate::io_end(MyEvent E){
	int device = E.t.TI[0].io_device;
	current_time = E.time_event;
	if (E.isFirstIO) {
		responseSum += current_time - E.processCreation;
		E.isFirstIO = false;
	}
	io_bool[device] = true;
	E.t.TI.erase(E.t.TI.begin());
	if (E.t.TI.empty()){
		cout << "task empty!" << endl;
		cout << "duriation: " << current_time - E.t.creationTime << endl;
	}
	else{
		if (Num_CPU>0){
			MyEvent temp(E.t, mem->getpage(E.t.TI[0].io_device) + current_time + E.t.TI[0].duration + context_switch, MyEvent::event_type::cpu_end, E.isFirstIO, E.processCreation);
			Pq_event.push(temp);
			Num_CPU--;
		}
		else{
			cpu_queue.push(E.t);
		}
	}
	if (io_bool[device]){
		if (!io_queue[device].empty()){
			task g = io_queue[device].front();
			io_queue[device].pop();
			MyEvent c(g, current_time + g.TI[0].duration + context_switch, MyEvent::event_type::Io_end, E.processCreation);
			Pq_event.push(c);
			io_bool[device] = false;
		}
		else{
			cout << "io_queue is empty!" << endl;
		}
	}
	else{
		cout << "Io_device is done!" << endl;
	}
}
void Approximate::simulator(){
	for (int i = 0; i < take.size(); i++){
		MyEvent temp(take[i], i*Task_frequency, MyEvent::event_type::creat);
		Pq_event.push(temp);
	}
	while (!Pq_event.empty()){
		MyEvent t = Pq_event.top(); Pq_event.pop();
		int current_time = t.time_event;
		switch (t.e_type)
		{
		case MyEvent::event_type::creat: create_event(t); break;
		case MyEvent::event_type::cpu_end: cpu_end(t); break;
		case MyEvent::event_type::Io_end: io_end(t); break;
		default:
			break;
		}
	}
	throughPut = numTasks / current_time;
	Efficiency = duriation / (current_time*Num_CPU);
}

