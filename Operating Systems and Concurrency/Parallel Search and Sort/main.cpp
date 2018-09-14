//xuecong fan
//use tutor center and google for this

#include <iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
#include <queue>
#include <atomic>
#include <iostream>
#include <condition_variable>
#include <mutex>
#include<thread>
#include <chrono>
#include <functional>
using namespace std;
class ThreadPool
{
public:
	ThreadPool(int n);
	~ThreadPool();
	void post(std::function<void(void)>);
	void stop();
	bool isDone() { return m_tasks.empty(); }
private:
	std::vector<std::thread> m_pool;
	std::queue<std::function<void(void)>>m_tasks;
	std::atomic<bool> m_continue;
	std::mutex m_mutex;
	std::condition_variable m_taskAdded;
};
ThreadPool::ThreadPool(int n) :m_pool(), m_tasks(), m_continue(true)
{
	for (int i = 0; i < n; ++i) {
		m_pool.emplace_back([&]() {
			
			while (m_continue) {
				//std::cout << "Threads are running." << std::endl;
				std::function<void(void)> f;
				{
					std::unique_lock<std::mutex> l(m_mutex);
					while (m_tasks.empty()){
						m_taskAdded.wait(l);
					}
					f = m_tasks.front();
					m_tasks.pop();

				}
				f();
			}
		});
	}

}

ThreadPool::~ThreadPool(){
	m_continue = false;
	for (auto && t : m_pool){
		t.join();
	}
}
void ThreadPool::stop(){
	m_continue = false;
}

void ThreadPool::post(std::function<void(void)> f){
	std::lock_guard <std::mutex>l(m_mutex);
	m_tasks.push(f);
	m_taskAdded.notify_one();
}




void quick_Sort(int start, int end, vector<int> & r)
{
	int mid = (end + start) / 2;
	int pivot = r[mid];
	int i = start;
	int j = end;
	while (i <= j){
		while (r[i] < pivot){
			i++;
		}

		while (r[j] > pivot){
			j--;
		}
		if (i <= j){
			int temp = r[i];
			r[i] = r[j];
			r[j] = temp;
			i++;
			j--;
		}
	}
		if (i < end){
			quick_Sort(i, end, r);
		}
		if (j > start){
			quick_Sort(start, j, r);

		}
	}


void print(vector<int> r, int num){
	int a = 0;
	while (a <= num){
		cout << r[a] << " ";
		a++;
	}
	cout << endl;
}

bool linear_search (vector<int> r,int size,int num){
	for (int i = 0; i <= size; i++){
		if (num == r[i]){
			return true;
		}
	}
	return false;
}



int main(){
	/*vector<int> r = { 110, 5, 10, 3, 22, 56, 89, 34 };
	quick_Sort(0, 7, r);
	print(r, 7);
	cout << linear_search(r, 7, 10) << endl;*/


	for (int i = 100; i <= 1000000; i *= 10){
		vector<int> v(i);
		generate(v.begin(), v.end(), []() { return rand() % 10 + 1;  });
		clock_t start_sort = clock();

		std::sort(v.begin(), v.end());

		clock_t end_sort = clock();
		double time_sort = (double)(end_sort - start_sort) / CLOCKS_PER_SEC;
		std::cout << "the time of sort:  " << time_sort << " second" << std::endl;

	}

	for (int i = 100; i <= 1000000; i *= 10){
		vector<int> r(i);
		generate(r.begin(), r.end(), []() { return rand() % 10 + 1;  });
		clock_t start_4 = clock();
	/*	quick_Sort(0, r.size() - 1, r);*/
		
		{
			ThreadPool threadPool(4);
			threadPool.post([&]() { quick_Sort(0, r.size() / 4, r); cout<<endl; });
			threadPool.post([&]() { quick_Sort(r.size() / 4, r.size() / 2, r); cout<< endl;  });
			threadPool.post([&]() { quick_Sort(r.size() / 2, 3 * r.size() / 4, r); std::cout <<endl;  });
			threadPool.post([&]() { quick_Sort(3 * r.size() / 4, r.size() - 1, r); std::cout << endl; });
		}
		clock_t end_4 = clock();
		double time4 = (double)(end_4 - start_4) / CLOCKS_PER_SEC;
		std::cout << "the time of threalPool_4:  " << time4 << " second" << std::endl;

	}
	cout << "---------------------------------------------" << endl;
	cout << "linear Search for 9 if find return 1." << endl;
	cout << "---------------------------------------------" << endl;
	for (int i = 100; i <= 1000000; i *= 10){
		vector<int> s(i);
		generate(s.begin(), s.end(), []() { return rand() ;  });
		clock_t start = clock();
		/*	quick_Sort(0, r.size() - 1, r);*/

		{
			ThreadPool threadPool(4);
			threadPool.post([&]() { cout<< linear_search(s, s.size() / 4, 9); std::cout << endl; });
			threadPool.post([&]() {cout<<linear_search(s,s.size() / 2 - s.size() / 4, 9); std::cout <<endl;  });
			threadPool.post([&]() { cout<<linear_search(s, 3 * s.size() / 4 - s.size() / 2, 9); std::cout << endl;  });
			threadPool.post([&]() {cout<<linear_search(s, (s.size() - 1) - 3 * s.size() / 4, 9); std::cout << endl; });
		}

		clock_t end = clock();
		double time = (double)(end - start) / CLOCKS_PER_SEC;
		std::cout << "the time of threalPool_4:  " << time << " second" << std::endl;
		
	}

	
	for (int i = 100; i <= 1000000; i *= 10){
		vector<int> d(i);
		generate(d.begin(), d.end(), []() { return rand() ;  });
		auto start_lr = chrono::high_resolution_clock::now();

	auto result = find(d.begin(), d.end(),9);
	if (result!= d.end()){
		cout << "find the num!" << endl;
	}
	else{
		cout << "not find" << endl;
	}
		auto end_lr = chrono::high_resolution_clock::now();
		auto time_lr = std::chrono::duration_cast<std::chrono::microseconds>(end_lr - start_lr).count();
		std::cout << "the time of find:  " << time_lr << " microsecond" << std::endl;

	}









	return 0;
}