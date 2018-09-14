//xuecong Fan
//9/9/2016
//used tutor center and google and youtube for this code

#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <cmath>
#include<chrono>
#include<vector>

#define x_wide 512
#define y_heigh 512
#define max_num 1000

using namespace std;
template<typename F>
double timeF(F f){
	auto start = std::chrono::steady_clock::now();
	f();
	auto end = std::chrono::steady_clock::now();
	return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}
double average(vector<double> v){
	double average;
	double sum = 0;
	for (int i = 0; i < v.size(); ++i){
		sum += v[i];
	}
	average = sum / v.size();
	return average;
}
double stand_deviation(vector<double> v,double average){
	double s_d;
	double sum = 0;
	for (int i = 0; i < v.size(); ++i){
		sum += pow(v[i]-average, 2);
	}

	s_d = sqrt(sum / v.size());

	return s_d;
}

struct Pix {
	short red;
	short blue;
	short green;
	Pix(short r, short b, short g) : red(r), blue(b), green(g) {}
};
int get_num(double, double, int);

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
		return Pix(p * 10 % 256, p * 7 % 255, p * 5 % 256);
	}
}
void mbrot() {
	int red;
	int blue;
	int green;

	

	ofstream fout("output.txt");
	fout << "P3" << endl;
	fout << x_wide << " " << y_heigh << endl;
	fout << "256" << endl;
	
	for (int i = 0; i < x_wide; ++i){
		for (int j = 0; j < y_heigh; ++j){
			auto pixel = get_pix(i, j);
			fout << pixel.red << " " << pixel.green << " " << pixel.blue << " ";
		}
		fout << endl;
	}

	cout << "Down" << endl;
}

int main(){
	std::vector<double> times;

	for (auto i = 0; i < 10; ++i) {
		times.push_back(timeF(mbrot));
	}
	double aver;
	aver = average(times);
	cout << "Average is : " << aver << endl;
	double st_de;
	st_de = stand_deviation(times, aver);
	cout << "stand deviation is : " << st_de << endl;


	

	return 0;
}

//while (x*x + y*y < 2 * 2  AND  iteration < max_iteration) {
//	xtemp = x*x - y*y + x0
//		y = 2 * x*y + y0
//		x = xtemp
//		iteration = iteration + 1
//}
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










