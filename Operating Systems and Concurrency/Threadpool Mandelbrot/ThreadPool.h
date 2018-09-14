#ifndef THREADPOOL_H
#define THREADPOOL_H
#include <mutex>
#include<thread>
#include <functional>
#include <vector>
#include <queue>
#include <atomic>
#include <iostream>
#include <condition_variable>
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
		std::atomic<bool> m_continue = true;
		std::mutex m_mutex;
		std::condition_variable m_taskAdded;
};

#endif