#ifndef SIMULATER_H
#define SIMULATER_H
#include <queue>
#include<iostream>
#include<random>
#include<vector>
using namespace std;
class memory{
public:
	memory(){
	};
	virtual int getpage(int page) = 0;
	memory(int size, int penalty){
		Size_of_cache = size;
		Cache_miss_penalty = penalty;
		page_distributions = size;
		cache = vector<int>(size, -1);
	}
	int getsize(){
		return Size_of_cache;
	}
	int total_cache_miss = 0;
protected:
	vector <int> cache;
	int Size_of_cache;
	int Cache_miss_penalty;
	int page_distributions;

};
enum taskType
{
	IO, CPU
};
struct taskIterm{
	taskIterm(taskType TP, double duration, int io_device = -1){
		this->TP = TP;
		this->duration = duration;
		this->io_device = io_device;

	}
	taskType TP;
	double duration;
	int io_device;
	////////////////////////

};
struct task{
	double duration = 0;
	vector<taskIterm> TI;

	double creationTime;
};
struct Event{
	enum event_type{
		Io_end, cpu_end, start, end, creat
	};
	Event(task tk, double dur, Event::event_type et, double fIO = true, double pC = 0){
		t = tk;
		time_event = dur;
		e_type = et;
		isFirstIO = fIO;

		if (et == event_type::creat) {
			processCreation = t.creationTime;
		}
		else {
			processCreation = pC;
		}
	}
	task t;
	double time_event = 0.0;
	bool operator < (const Event & r) const{
		return time_event < r.time_event;
	}
	event_type e_type;
	bool isFirstIO = true;
	bool islastCPU = true;
	double processCreation;
	/*bool isLastcpu = true;
	bool isthput = true;*/
};
struct compare{
	bool operator()(const Event& l, const Event& r){
		return l.time_event < r.time_event;
	}


};
class simulater{
public:
	double Task_mix = 0.5;
	double Task_frequency = 5;
	double Num_CPU = 6;
	double Num_IO = 8;
	double context_switch = 1;
	double current_time = 0;


	vector<task>take;
	priority_queue<Event> Pq_event;
	memory* mem;
	queue<task> cpu_queue;
	vector<queue<task>> io_queue;
	vector<bool> io_bool;

	void creat_tasks();
	void simulator();
	void create_event(Event);
	void cpu_end(Event);
	void io_end(Event);


	simulater() {
		io_queue.resize(Num_IO);
		io_bool.resize(Num_IO, true);
	}

	double getResponseTime() {
		return responseSum / (double)numTasks;
	}
	double Latency(){
		return Laten_sum / (double)numTasks;
	}
	double Through_put(){
		return throughPut;
	}
	double efficiency(){
		return Efficiency;
	}
private:

	double random(double low, double high);
	int random1(int low, int high);


	task get_CPU_task();
	task get_Io_task();

	double responseSum = 0.0;
	unsigned int eventCount = 0;
	double 	Laten_sum = 0.0;
	int numTasks;
	double throughPut = 0.0;
	double Efficiency = 0.0;
	double duriation = 0.0;


};

//////memory///////////////////////////////////////////

class Fifo :public memory{
public:
	Fifo(int a, int b) : memory(a, b){
		hold_page = vector<int>(Size_of_cache, -1);
	}
	vector <int> hold_page;
	Fifo(){
		cur = 0;
		hold_page.resize(Size_of_cache);
		for (int i = 0; i < Size_of_cache; i++){
			hold_page[i] = -1;
		}
	};
	bool insert(int page);

protected:
	int cur;
	int getpage(int page);
};
class second_Chance :public memory{
public:
	second_Chance(int a, int b) : memory(a, b){
		hold_page = vector<int>(Size_of_cache, -1);
		check_mark = vector<bool>(Size_of_cache, false);
	}
	second_Chance(){
		cur = 0;
		hold_page.resize(Size_of_cache);
		check_mark.resize(Size_of_cache);
		for (int i = 0; i < Size_of_cache; i++){
			hold_page[i] = -1;
			check_mark[i] = false;
		}

	};
	vector <int> hold_page;
	vector<bool> check_mark;

protected:
	int cur;
	int getpage(int page);
};
class Most_Recently : public memory{
public:
	Most_Recently(int a, int b) : memory(a, b){
		hold_page = vector<int>(Size_of_cache, -1);
	}
	vector <int> hold_page;
	Most_Recently(){
		cur = 0;
		hold_page.resize(Size_of_cache);
		for (int i = 0; i < Size_of_cache; i++){
			hold_page[i] = -1;
		}
	};

protected:
	int cur;
	bool filled;
	int getpage(int page);

};
class Last_Recently :public memory {
public:
	Last_Recently(int a, int b) : memory(a, b){
		hold_page = vector<int>(Size_of_cache, -1);
		count_num = vector<int>(Size_of_cache, 0);
	}
	vector <int> hold_page;
	vector <int> count_num;
	Last_Recently(){
		cur = 0;
		hold_page.resize(Size_of_cache);
		for (int i = 0; i < Size_of_cache; i++){
			hold_page[i] = -1;
			count_num[i] = 0;
		}
	};
protected:
	int cur;
	int getpage(int page);
};

///////////roundRobin///////////////////////////////////////////

class roundRobin{
public:
	double Task_mix = 0.5;
	double Task_frequency = 5;
	double Num_CPU = 6;
	double Num_IO = 8;
	double context_switch = 1;
	double current_time = 0;

	double time_limit = 10;

	vector<task>take;
	priority_queue<Event> Pq_event;
	memory* mem;
	queue<task> cpu_queue;
	vector<queue<task>> io_queue;
	vector<bool> io_bool;

	void creat_tasks();
	void simulator();
	void create_event(Event);
	void cpu_end(Event);
	void io_end(Event);

	roundRobin() {
		io_queue.resize(Num_IO);
		io_bool.resize(Num_IO, true);
	}

	double getResponseTime() {
		return responseSum / (double)numTasks;
	}
	double Latency(){
		return Laten_sum / (double)numTasks;
	}
	double Through_put(){
		return throughPut;
	}
	double efficiency(){
		return Efficiency;
	}
private:

	double random(double low, double high);
	int random1(int low, int high);


	task get_CPU_task();
	task get_Io_task();

	double responseSum = 0.0;
	unsigned int eventCount = 0;
	double 	Laten_sum = 0.0;
	int numTasks;
	double throughPut = 0.0;
	double Efficiency = 0.0;
	double duriation = 0.0;


};
//////////Shortest job first///////////////////////////////////
class ShortestFirst{
public:
	double Task_mix = 0.5;
	double Task_frequency = 5;
	double Num_CPU = 6;
	double Num_IO = 8;
	double context_switch = 1;
	double current_time = 0;

	struct MyEvent : public Event {
		MyEvent(task tk, double dur, MyEvent::event_type et, double fIO = true, double pC = 0) : Event(tk, dur, et, fIO, pC) {}
	};

	vector<task>take;
	priority_queue<MyEvent> Pq_event;
	memory* mem;
	queue<task> cpu_queue;
	vector<queue<task>> io_queue;
	vector<bool> io_bool;

	void creat_tasks();
	void simulator();
	void create_event(MyEvent);
	void cpu_end(MyEvent);
	void io_end(MyEvent);


	ShortestFirst() {
		io_queue.resize(Num_IO);
		io_bool.resize(Num_IO, true);
	}

	double getResponseTime() {
		return responseSum / (double)numTasks;
	}
	double Latency(){
		return Laten_sum / (double)numTasks;
	}
	double Through_put(){
		return throughPut;
	}
	double efficiency(){
		return Efficiency;
	}
private:

	double random(double low, double high);
	int random1(int low, int high);


	task get_CPU_task();
	task get_Io_task();

	double responseSum = 0.0;
	unsigned int eventCount = 0;
	double 	Laten_sum = 0.0;
	int numTasks;
	double throughPut = 0.0;
	double Efficiency = 0.0;
	double duriation = 0.0;

};

/////////approximate shortest job first////////////////////////
class Approximate{
public:
	double Task_mix = 0.5;
	double Task_frequency = 5;
	double Num_CPU = 6;
	double Num_IO = 8;
	double context_switch = 1;
	double current_time = 0;

	struct MyEvent : public Event {
		MyEvent(task tk, double dur, MyEvent::event_type et, double fIO = true, double pC = 0) : Event(tk, dur, et, fIO, pC) {}
	};

	vector<task>take;
	priority_queue<MyEvent> Pq_event;
	memory* mem;
	queue<task> cpu_queue;
	vector<queue<task>> io_queue;
	vector<bool> io_bool;

	void creat_tasks();
	void simulator();
	void create_event(MyEvent);
	void cpu_end(MyEvent);
	void io_end(MyEvent);


	Approximate() {
		io_queue.resize(Num_IO);
		io_bool.resize(Num_IO, true);
	}

	double getResponseTime() {
		return responseSum / (double)numTasks;
	}
	double Latency(){
		return Laten_sum / (double)numTasks;
	}
	double Through_put(){
		return throughPut;
	}
	double efficiency(){
		return Efficiency;
	}
private:

	double random(double low, double high);
	int random1(int low, int high);


	task get_CPU_task();
	task get_Io_task();

	double responseSum = 0.0;
	unsigned int eventCount = 0;
	double 	Laten_sum = 0.0;
	int numTasks;
	double throughPut = 0.0;
	double Efficiency = 0.0;
	double duriation = 0.0;

};








#endif;