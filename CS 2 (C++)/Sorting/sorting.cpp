//xuecong fan
//A01972388
//use lecture and class way for most this code
#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <functional>
#include <algorithm>

using namespace std;
void timesort(int size, std::function<void(std::vector<int>&)>function);

int getrand(int low, int high){
	static std::random_device rd;
	static std:: mt19937 mt(rd());
	std::uniform_int_distribution<> dist (low, high);
	return dist (mt);
}
std::vector<int>generate(int size){
	std::vector<int> c(size);
	for (auto & e : c){
		e = getrand(0, size);
		return c;
	}
	
}
void stdsort(std::vector<int>c){
	std::sort(c.begin(), c.end());
}
void bubbleSort(std::vector<int>& c);
void insertionSort(std::vector<int>& c);
void selectionSort(std::vector<int> & c);
void mergesort(std::vector<int> &c);
void qSort(std::vector<int>c, int lo, int hi);
void quickSort(std::vector<int> & c);
int partition(std::vector<int>c, int lo, int hi);






int main(){

	std::cout << "std::sort" << std::endl;
	for (int size = 100; size < 1000; size *= 10){
		timesort(size, stdsort);
	}
	std::cout << "bubblesort" << std::endl;
	for (int size = 100; size < 1000; size *= 10){
		timesort(size, bubbleSort);
	}
	std::cout << "insertionSort" << std::endl;
	for (int size = 100; size < 1000; size *= 10){
		timesort(size, insertionSort);
	}
	std::cout << "selectionSort" << std::endl;
	for (int size = 100; size < 1000; size *= 10){
		timesort(size, selectionSort);
	}
	std::cout << " mergesort" << std::endl;
	for (int size = 100; size < 1000; size *= 10)
	{
		timesort(size, mergesort);
	}

	std::cout << "quickSort " << std::endl;
	for (int size = 100; size < 1000; size *= 10)
	{
		timesort(size, quickSort);
	}

	








	return 0;
}
void bubbleSort(std::vector<int>& c){
	auto done = false;
	while (!done){
		done = true;
		for (auto i = 0u; i < c.size() - 1; ++i){
			if (c[i]>c[i + 1]){
				std::swap(c[i], c[i + 1]);
				done = false;
			}
		}
	}

}
void insertionSort(std::vector<int>& c){
	for (auto i = 1; i < c.size(); ++i){
		for (auto j = 0; j < i; ++j){
			if (c[i] < c[j])std::swap(c[i], c[j]);
		}
	}
}
void selectionSort(std::vector<int> & c){

	for (int i = 0; i < c.size() - 1; ++i){
		int min = i;
		for (int j = i + 1; j < c.size(); ++j){
			if (c[j] < c[min]){
				min = j;
			}
		}
		if (min != i){
			std::swap(c[i], c[min]);
		}
	}
}


void mergesort(std::vector<int> &c){
	
	if (c.size() <= 1){
		return;
	}
	int mid = (c.size()) / 2;


	vector<int>a{ c.begin(), c.begin() + mid };
	vector<int>b{ c.begin() + mid, c.end() };
	mergesort(a);
	mergesort(b);

	std::swap(a, b);
}
void qSort(std::vector<int>c,int lo, int hi){
	
	if (lo < hi){
		int p = partition(c, lo, hi);
		qSort(c, lo, p - 1);
		qSort(c, p + 1, hi);
	}

}
int partition(std::vector<int>c, int lo, int hi){
	int pivot = c[hi];
	int swaplocation = lo;
	for (int i = lo; i < hi; ++i){
		if (c[i] <= pivot){
			std::swap(c[swaplocation], c[i]);
			swaplocation++;
		}
	}
	std::swap(c[swaplocation], c[hi]);
	return swaplocation;
}
void quickSort(std::vector<int> & c){
	qSort(c, 0, c.size() - 1);
}
void timesort(int size, std::function<void(std::vector<int>&)>function){

	std::vector<int>& v = generate(size);
	auto start = std::chrono::system_clock::now();
	function(v);
	auto end = std::chrono::system_clock::now();
	auto duration = end - start;
	auto sec = std::chrono::duration_cast<std::chrono::duration<float>>(duration);
	std::cout << "size: " << size << "\tTime: " << sec.count() << endl;
}