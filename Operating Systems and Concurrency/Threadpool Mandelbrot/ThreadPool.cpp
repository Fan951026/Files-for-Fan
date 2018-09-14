#include"ThreadPool.h"
#include <iostream>


ThreadPool::ThreadPool(int n) :m_pool(), m_tasks()
{
	for (int i = 0; i < n; ++i) {
		m_pool.emplace_back([&]() {
			while (m_continue) {
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