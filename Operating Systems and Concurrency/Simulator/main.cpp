//Use tutor center and google for this assignment 
//xuecong fan
#include"Fifo.h"
#include"memory.h"
#include<iostream>
#include<vector>
#include<random>
#include<fstream>
#include <queue>



using namespace std;



int choice_Fifo(){
	simulater si;
	roundRobin rd;
	ShortestFirst sf;
	Approximate ap;
	int size_cache; int miss_penalty;
	cout << "pleace enter size of cache: ";
	cin >> size_cache;
	cout << "pleace enter cache miss penalty: ";
	cin >> miss_penalty;
	char input2 = 'w';
	cout << "Which simulator you choice?" << endl;
	cout << "A:Fifo Algorithms" << endl;
	cout << "B:Round Robin Algorithms" << endl;
	cout << "C:Shortest job First Algorithms" << endl;
	cout << "D:Approximate Shortest Job First Algorithms" << endl;
	cout << "Q:Quit!" << endl;
	cin >> input2;
	switch (input2)
	{
	case 'A':
	case 'a':
		si.mem = new Fifo(size_cache, miss_penalty);
		si.creat_tasks();
		si.simulator();
		cout << "------------------------------" << endl;
		cout << "total_cache_miss: " << si.mem->total_cache_miss << endl;
		cout << "Response Time: " << si.getResponseTime() << endl;
		cout << "Latency Time: " << si.Latency() << endl;
		cout << "Throughput: " << si.Through_put() << endl;
		cout << "Efficiency: " << si.efficiency() << endl;
		cout << "------------------------------" << endl;
		break;
	case 'B':
	case 'b':
		rd.mem = new Fifo(size_cache, miss_penalty);
		rd.creat_tasks();
		rd.simulator();
		cout << "------------------------------" << endl;
		cout << "total_cache_miss: " << rd.mem->total_cache_miss << endl;
		cout << "Response Time: " << rd.getResponseTime() << endl;
		cout << "Latency Time: " << rd.Latency() << endl;
		cout << "Throughput: " << rd.Through_put() << endl;
		cout << "Efficiency: " << rd.efficiency() << endl;
		cout << "------------------------------" << endl;
		break;
	case 'C':
	case 'c':
		sf.mem = new Fifo(size_cache, miss_penalty);
		sf.creat_tasks();
		sf.simulator();
		cout << "------------------------------" << endl;
		cout << "total_cache_miss: " << sf.mem->total_cache_miss << endl;
		cout << "Response Time: " << sf.getResponseTime() << endl;
		cout << "Latency Time: " << sf.Latency() << endl;
		cout << "Throughput: " << sf.Through_put() << endl;
		cout << "Efficiency: " << sf.efficiency() << endl;
		cout << "------------------------------" << endl;
		break;
	case 'D':
	case 'd':
		ap.mem = new Fifo(size_cache, miss_penalty);
		ap.creat_tasks();
		ap.simulator();
		cout << "------------------------------" << endl;
		cout << "total_cache_miss: " << ap.mem->total_cache_miss << endl;
		cout << "Response Time: " << ap.getResponseTime() << endl;
		cout << "Latency Time: " << ap.Latency() << endl;
		cout << "Throughput: " << ap.Through_put() << endl;
		cout << "Efficiency: " << ap.efficiency() << endl;
		cout << "------------------------------" << endl;
		break;
	case 'Q':
	case 'q':
		cout << "You quiet!" << endl;
		return 0;
		break;
	default:
		break;
	}

}
int choice_Second(){
	simulater si;
	roundRobin rd;
	ShortestFirst sf;
	Approximate ap;
	int size_cache; int miss_penalty;
	cout << "pleace enter size of cache: ";
	cin >> size_cache;
	cout << "pleace enter cache miss penalty: ";
	cin >> miss_penalty;
	char input2 = 'w';
	cout << "Which simulator you choice?" << endl;
	cout << "A:Fifo Algorithms" << endl;
	cout << "B:Round Robin Algorithms" << endl;
	cout << "C:Shortest job First Algorithms" << endl;
	cout << "D:Approximate Shortest Job First Algorithms" << endl;
	cout << "Q:Quit!" << endl;
	cin >> input2;
	switch (input2)
	{
	case 'A':
	case 'a':
		si.mem = new second_Chance(size_cache, miss_penalty);
		si.creat_tasks();
		si.simulator();
		cout << "------------------------------" << endl;
		cout << "total_cache_miss: " << si.mem->total_cache_miss << endl;
		cout << "Response Time: " << si.getResponseTime() << endl;
		cout << "Latency Time: " << si.Latency() << endl;
		cout << "Throughput: " << si.Through_put() << endl;
		cout << "Efficiency: " << si.efficiency() << endl;
		cout << "------------------------------" << endl;
		break;
	case 'B':
	case 'b':
		rd.mem = new second_Chance(size_cache, miss_penalty);
		rd.creat_tasks();
		rd.simulator();
		cout << "------------------------------" << endl;
		cout << "total_cache_miss: " << rd.mem->total_cache_miss << endl;
		cout << "Response Time: " << rd.getResponseTime() << endl;
		cout << "Latency Time: " << rd.Latency() << endl;
		cout << "Throughput: " << rd.Through_put() << endl;
		cout << "Efficiency: " << rd.efficiency() << endl;
		cout << "------------------------------" << endl;
		break;
	case 'C':
	case 'c':
		sf.mem = new second_Chance(size_cache, miss_penalty);
		sf.creat_tasks();
		sf.simulator();
		cout << "------------------------------" << endl;
		cout << "total_cache_miss: " << sf.mem->total_cache_miss << endl;
		cout << "Response Time: " << sf.getResponseTime() << endl;
		cout << "Latency Time: " << sf.Latency() << endl;
		cout << "Throughput: " << sf.Through_put() << endl;
		cout << "Efficiency: " << sf.efficiency() << endl;
		cout << "------------------------------" << endl;
		break;
	case 'D':
	case 'd':
		ap.mem = new second_Chance(size_cache, miss_penalty);
		ap.creat_tasks();
		ap.simulator();
		cout << "------------------------------" << endl;
		cout << "total_cache_miss: " << ap.mem->total_cache_miss << endl;
		cout << "Response Time: " << ap.getResponseTime() << endl;
		cout << "Latency Time: " << ap.Latency() << endl;
		cout << "Throughput: " << ap.Through_put() << endl;
		cout << "Efficiency: " << ap.efficiency() << endl;
		cout << "------------------------------" << endl;
		break;
	case 'Q':
	case 'q':
		cout << "You quiet!" << endl;

		return 0;
	default:
		break;
	}

}
int choice_Most(){
	simulater si;
	roundRobin rd;
	ShortestFirst sf;
	Approximate ap;
	int size_cache; int miss_penalty;
	cout << "pleace enter size of cache: ";
	cin >> size_cache;
	cout << "pleace enter cache miss penalty: ";
	cin >> miss_penalty;
	char input2 = 'w';
	cout << "Which simulator you choice?" << endl;
	cout << "A:Fifo Algorithms" << endl;
	cout << "B:Round Robin Algorithms" << endl;
	cout << "C:Shortest job First Algorithms" << endl;
	cout << "D:Approximate Shortest Job First Algorithms" << endl;
	cout << "Q:Quit!" << endl;
	cin >> input2;
	switch (input2)
	{
	case 'A':
	case 'a':
		si.mem = new Most_Recently(size_cache, miss_penalty);
		si.creat_tasks();
		si.simulator();
		cout << "------------------------------" << endl;
		cout << "total_cache_miss: " << si.mem->total_cache_miss << endl;
		cout << "Response Time: " << si.getResponseTime() << endl;
		cout << "Latency Time: " << si.Latency() << endl;
		cout << "Throughput: " << si.Through_put() << endl;
		cout << "Efficiency: " << si.efficiency() << endl;
		cout << "------------------------------" << endl;
		break;
	case 'B':
	case 'b':
		rd.mem = new Most_Recently(size_cache, miss_penalty);
		rd.creat_tasks();
		rd.simulator();
		cout << "------------------------------" << endl;
		cout << "total_cache_miss: " << rd.mem->total_cache_miss << endl;
		cout << "Response Time: " << rd.getResponseTime() << endl;
		cout << "Latency Time: " << rd.Latency() << endl;
		cout << "Throughput: " << rd.Through_put() << endl;
		cout << "Efficiency: " << rd.efficiency() << endl;
		cout << "------------------------------" << endl;
		break;
	case 'C':
	case 'c':
		sf.mem = new Most_Recently(size_cache, miss_penalty);
		sf.creat_tasks();
		sf.simulator();
		cout << "------------------------------" << endl;
		cout << "total_cache_miss: " << sf.mem->total_cache_miss << endl;
		cout << "Response Time: " << sf.getResponseTime() << endl;
		cout << "Latency Time: " << sf.Latency() << endl;
		cout << "Throughput: " << sf.Through_put() << endl;
		cout << "Efficiency: " << sf.efficiency() << endl;
		cout << "------------------------------" << endl;
		break;
	case 'D':
	case 'd':
		ap.mem = new Most_Recently(size_cache, miss_penalty);
		ap.creat_tasks();
		ap.simulator();
		cout << "------------------------------" << endl;
		cout << "total_cache_miss: " << ap.mem->total_cache_miss << endl;
		cout << "Response Time: " << ap.getResponseTime() << endl;
		cout << "Latency Time: " << ap.Latency() << endl;
		cout << "Throughput: " << ap.Through_put() << endl;
		cout << "Efficiency: " << ap.efficiency() << endl;
		cout << "------------------------------" << endl;
		break;
	case 'Q':
	case 'q':
		cout << "You quiet!" << endl;
		return 0;
	default:
		break;
	}

}
int choice_least(){
	simulater si;
	roundRobin rd;
	ShortestFirst sf;
	Approximate ap;
	int size_cache; int miss_penalty;
	cout << "pleace enter size of cache: ";
	cin >> size_cache;
	
	cout << "pleace enter cache miss penalty: ";
	cin >> miss_penalty;
	char input2 = 'w';
	cout << "Which simulator you choice?" << endl;
	cout << "A:Fifo Algorithms" << endl;
	cout << "B:Round Robin Algorithms" << endl;
	cout << "C:Shortest job First Algorithms" << endl;
	cout << "D:Approximate Shortest Job First Algorithms" << endl;
	cout << "Q:Quit!" << endl;
	cin >> input2;
	switch (input2)
	{
	case 'A':
	case 'a':
		si.mem = new Last_Recently(size_cache, miss_penalty);
		si.creat_tasks();
		si.simulator();
		cout << "------------------------------" << endl;
		cout << "total_cache_miss: " << si.mem->total_cache_miss << endl;
		cout << "Response Time: " << si.getResponseTime() << endl;
		cout << "Latency Time: " << si.Latency() << endl;
		cout << "Throughput: " << si.Through_put() << endl;
		cout << "Efficiency: " << si.efficiency() << endl;
		cout << "------------------------------" << endl;
		break;
	case 'B':
	case 'b':
		rd.mem = new Last_Recently(size_cache, miss_penalty);
		rd.creat_tasks();
		rd.simulator();
		cout << "------------------------------" << endl;
		cout << "total_cache_miss: " << rd.mem->total_cache_miss << endl;
		cout << "Response Time: " << rd.getResponseTime() << endl;
		cout << "Latency Time: " << rd.Latency() << endl;
		cout << "Throughput: " << rd.Through_put() << endl;
		cout << "Efficiency: " << rd.efficiency() << endl;
		cout << "------------------------------" << endl;
		break;
	case 'C':
	case 'c':
		sf.mem = new Last_Recently(size_cache, miss_penalty);
		sf.creat_tasks();
		sf.simulator();
		cout << "------------------------------" << endl;
		cout << "total_cache_miss: " << sf.mem->total_cache_miss << endl;
		cout << "Response Time: " << sf.getResponseTime() << endl;
		cout << "Latency Time: " << sf.Latency() << endl;
		cout << "Throughput: " << sf.Through_put() << endl;
		cout << "Efficiency: " << sf.efficiency() << endl;
		cout << "------------------------------" << endl;
		break;
	case 'D':
	case 'd':
		ap.mem = new Last_Recently(size_cache, miss_penalty);
		ap.creat_tasks();
		ap.simulator();
		cout << "------------------------------" << endl;
		cout << "total_cache_miss: " << ap.mem->total_cache_miss << endl;
		cout << "Response Time: " << ap.getResponseTime() << endl;
		cout << "Latency Time: " << ap.Latency() << endl;
		cout << "Throughput: " << ap.Through_put() << endl;
		cout << "Efficiency: " << ap.efficiency() << endl;
		cout << "------------------------------" << endl;
		break;
	case 'Q':
	case 'q':
		cout << "You quiet!" << endl;
		return 0;
	default:
		break;
	}

}
int main(){

	/*memory mem;*/



	cout << "I choose:" << endl;
	cout << " Task_mix = 0.5" << endl;
	cout << "Task_frequency = 5" << endl;
	cout << "Num_CPU = 6" << endl;
	cout << "Num_IO = 8" << endl;
	cout << "context_switch = 1 " << endl;
	cout << "----------------------------------" << endl;
	char input = 'a';
	while (true)
	{


		cout << "which Memory Algorithms you choise?" << endl;
		cout << "A: Fifo Algorithms" << endl;
		cout << "B: Second Chance Algorithms" << endl;
		cout << "C: Most Resently used " << endl;
		cout << "D: least Resently used " << endl;
		cout << "Q: quit!" << endl;
		cout << "--------------------------------------" << endl;
		cin >> input;
		cout << endl;
		switch (input)
		{
		case 'A':
		case 'a':
			choice_Fifo();
			break;
		case 'B':
		case 'b':
			choice_Second();
			break;
		case 'C':
		case 'c':
			choice_Most();
			break;
		case 'D':
		case 'd':
			choice_least();
			break;
		case'Q':
		case 'q':
			cout << "You quit!" << endl;
			return 0;
			break;
		default:
			break;
		}




	}






	//Response Time - Time from process creation to first I/O completion
	//Latency - Time from process creation to final CPU completion
	//Throughput - Number of completed processes per unit time
	//Efficiency - Percentage of time spent with CPUs occupied with useful work(context switching does not count)








	return 0;
}