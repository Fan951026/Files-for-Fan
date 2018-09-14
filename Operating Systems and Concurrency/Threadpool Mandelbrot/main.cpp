#include"ThreadPool.h"
#include<iostream>
#include <string>
#include <fstream>
#include <string>
#include <cmath>
#include<chrono>
#include<vector>
#include<thread>
#include <ctime>
#include <mutex>
#include<thread>
#include <functional>
#include <vector>
#include <queue>
#include <atomic>
#include <iostream>
#include <condition_variable>

using namespace std;
#define x_wide 512
#define y_heigh 512
#define max_num 1000

int get_num(double x0, double y0, int max_iterations){
	double xtemp;
	int num = 0;
	double x = 0;
	double y = 0;
	while (x*x + y*y < 2 * 2 && num < max_iterations){
		xtemp = x*x - y*y + x0;
		y = 2 * x*y + y0;
		x = xtemp;
		num++;
	}
	return num;
}
struct Pix {
	short red;
	short blue;
	short green;
	Pix(short r, short b, short g) : red(r), blue(b), green(g) {}
};
Pix get_pix(int row, int col){
	double r1 = -2.5;
	double r2 = 1.0;
	double im1 = -1.5;
	double im2 = 2.0;
	double x0 = (r2 - r1) / x_wide * col + r1;
	double y0 = (im2 - im1) / y_heigh * row + im1;

	int p = get_num(x0, y0, max_num);

	if (p == max_num){
		return Pix(0, 0, 0);
	}
	else {
		//std::cout << p << std::endl;
		return Pix(p * 10 % 256, p * 7 % 255, p * 5 % 256);
	}
}
int img[x_wide * 3][y_heigh];

void call_from_thread(int a, int b){
	int red;
	int blue;
	int green;
	for (int i = a; i < b; ++i){
		for (int j = 0; j < y_heigh; ++j){
			auto pixel = get_pix(i, j);
			img[i * 3][j] = pixel.red;
			img[i * 3 + 1][j] = pixel.green;
			img[i * 3 + 2][j] = pixel.blue;
		}
	}

	cout << "Down" << endl;

}
int main(){


	ofstream fout_8("output_thread_8.ppm");
	fout_8 << "P3" << endl;
	fout_8 << x_wide << " " << y_heigh << endl;
	fout_8 << "256" << endl;



	clock_t start_8 = clock();


	{

		ThreadPool threadPool(8);

		threadPool.post([&]() { call_from_thread(0, x_wide / 8); });
		threadPool.post([&]() { call_from_thread(x_wide / 8, x_wide / 4); });
		threadPool.post([&]() { call_from_thread(x_wide / 4, 3 * x_wide / 8); });
		threadPool.post([&]() { call_from_thread(3 * x_wide / 8, x_wide / 2); });
		threadPool.post([&]() { call_from_thread(x_wide / 2, 5 * x_wide / 8); });
		threadPool.post([&]() { call_from_thread(5 * x_wide / 8, 3 * x_wide / 4); });
		threadPool.post([&]() { call_from_thread(3 * x_wide / 4, 7 * x_wide / 8); });
		threadPool.post([&]() { call_from_thread(7 * x_wide / 8, x_wide); });
	}



	clock_t end_8 = clock();
	double time = (double)(end_8 - start_8) / CLOCKS_PER_SEC;

	std::cout << "the time of threalPool_8:  " << time << " second" <<std::endl;

	cout << "will print" << endl;
	for (int i = 0; i < x_wide * 3; i += 3){

		for (int j = 0; j < y_heigh; ++j){
			auto pixel = get_pix(i, j);
			fout_8 << img[i][j] << " " << img[i + 1][j] << " " << img[i + 2][j] << " ";

		}
		fout_8 << endl;
	}
	cout << "done printing" << endl;



	ofstream fout_4("output_thread_4.ppm");
	fout_8 << "P3" << endl;
	fout_8 << x_wide << " " << y_heigh << endl;
	fout_8 << "256" << endl;



	clock_t start_4 = clock();


	{

		ThreadPool threadPool(4);

		threadPool.post([&]() { call_from_thread( 0, x_wide / 4); });
		threadPool.post([&]() { call_from_thread(x_wide / 4, x_wide / 2); });
		threadPool.post([&]() { call_from_thread(x_wide / 2, 3 * x_wide / 4); });
		threadPool.post([&]() { call_from_thread(3 * x_wide / 4, x_wide ); });

	}



	clock_t end_4 = clock();
	double time4 = (double)(end_4 - start_4) / CLOCKS_PER_SEC;

	std::cout << "the time of threalPool_4:  " << time4 << " second" << std::endl;

	cout << "will print" << endl;
	for (int i = 0; i < x_wide * 3; i += 3){

		for (int j = 0; j < y_heigh; ++j){
			auto pixel = get_pix(i, j);
			fout_4 << img[i][j] << " " << img[i + 1][j] << " " << img[i + 2][j] << " ";

		}
		fout_4 << endl;
	}
	cout << "done printing" << endl;












	//ofstream fout_all("output_thread_all.ppm");
	//fout_8 << "P3" << endl;
	//fout_8 << x_wide << " " << y_heigh << endl;
	//fout_8 << "256" << endl;



	//clock_t start_all = clock();


	//{

	//	ThreadPool threadPool(512);

	//	threadPool.post([&]() { call_from_thread(0, x_wide); });


	//}



	//clock_t end_all = clock();
	//double timeall = (double)(end_all - start_all) / CLOCKS_PER_SEC;

	//std::cout << "the time of threalPool_all:  " << timeall << " second" << std::endl;

	//cout << "will print" << endl;
	//for (int i = 0; i < x_wide * 3; i += 3){

	//	for (int j = 0; j < y_heigh; ++j){
	//		auto pixel = get_pix(i, j);
	//		fout_all << img[i][j] << " " << img[i + 1][j] << " " << img[i + 2][j] << " ";

	//	}
	//	fout_all << endl;
	//}
	//cout << "done printing" << endl;







	/*const int num_threads = 512;
	ofstream fout("output_thread.ppm");
	fout << "P3" << endl;
	fout << x_wide << " " << y_heigh << endl;
	fout << "256" << endl;
	thread t[num_threads];
	clock_t start1 = clock();
	for (int i = 0; i < 512; i++){
		t[i] = thread(call_from_thread, i, i+1);
		
	}
	clock_t end1 = clock();
	for (int i = 0; i < num_threads; ++i){
		t[i].join();
	}
	
	double time1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
	std::cout << "the time of 1 row :  " << time1 << " second" << std::endl;
	cout << "will print" << endl;
	for (int i = 0; i < x_wide * 3; i += 3){

		for (int j = 0; j < y_heigh; ++j){
			auto pixel = get_pix(i, j);
			fout << img[i][j] << " " << img[i + 1][j] << " " << img[i + 2][j] << " ";

		}
		fout << endl;
	}
	cout << "done printing" << endl;*/


	return 0;
}