#include <iostream>
#include <string>
#include <fstream>
#include <string>
#include <cmath>
#include<chrono>
#include<vector>
#include<thread>
#include <ctime>
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
		return Pix(p * 10 % 256, p * 7 % 255, p * 5 % 256);
	}
}

void image1(){
	    int red;
		int blue;
		int green;
	
	
	
		ofstream fout("output_4.ppm");
		fout << "P3" << endl;
		fout << x_wide << " " << y_heigh << endl;
		fout << "256" << endl;
	
		for (int i = 0; i < x_wide/4; ++i){
			for (int j = 0; j < y_heigh; ++j){
				auto pixel = get_pix(i, j);
				fout << pixel.red << " " << pixel.green << " " << pixel.blue << " ";
			}
			fout << endl;
		}
	
		cout << "Down1" << endl;
}

void image2(){
	int red;
	int blue;
	int green;



	ofstream fout;
	fout.open("output_4.ppm", fstream::app);

	for (int i = x_wide/4; i < x_wide/2; ++i){
		for (int j = 0; j < y_heigh; ++j){
			auto pixel = get_pix(i, j);
			fout << pixel.red << " " << pixel.green << " " << pixel.blue << " ";
		}
		fout << endl;
	}

	cout << "Down2" << endl;
}
void image3(){
	int red;
	int blue;
	int green;

	ofstream fout;
	fout.open("output_4.ppm", fstream::app);
	

	for (int i = x_wide/2; i < 3*x_wide/4; ++i){
		for (int j = 0; j < y_heigh ; ++j){
			auto pixel = get_pix(i, j);
			fout << pixel.red << " " << pixel.green << " " << pixel.blue << " ";
		}
		fout << endl;
	}

	cout << "Down3" << endl;
}
void image4(){
	int red;
	int blue;
	int green;

	ofstream fout;
	fout.open("output_4.ppm", fstream::app);
	for (int i = 3*x_wide/4; i < x_wide; ++i){
		for (int j = 0; j < y_heigh; ++j){
			auto pixel = get_pix(i, j);
			fout << pixel.red << " " << pixel.green << " " << pixel.blue << " ";
		}
		fout << endl;
	}

	cout << "Down4" << endl;
}
void image_1(){
	int red;
	int blue;
	int green;



	ofstream fout("output_8.ppm");
	fout << "P3" << endl;
	fout << x_wide << " " << y_heigh << endl;
	fout << "256" << endl;

	for (int i = 0; i < x_wide / 8; ++i){
		for (int j = 0; j < y_heigh; ++j){
			auto pixel = get_pix(i, j);
			fout << pixel.red << " " << pixel.green << " " << pixel.blue << " ";
		}
		fout << endl;
	}

	cout << "Down1" << endl;
}
void image_2(){
	int red;
	int blue;
	int green;



	ofstream fout;
	fout.open("output_8.ppm", fstream::app);

	for (int i = x_wide / 8; i < x_wide / 4; ++i){
		for (int j = 0; j < y_heigh; ++j){
			auto pixel = get_pix(i, j);
			fout << pixel.red << " " << pixel.green << " " << pixel.blue << " ";
		}
		fout << endl;
	}

	cout << "Down2" << endl;
}
void image_3(){
	int red;
	int blue;
	int green;



	ofstream fout;
	fout.open("output_8.ppm", fstream::app);

	for (int i = x_wide / 4; i < 3*x_wide / 8; ++i){
		for (int j = 0; j < y_heigh; ++j){
			auto pixel = get_pix(i, j);
			fout << pixel.red << " " << pixel.green << " " << pixel.blue << " ";
		}
		fout << endl;
	}

	cout << "Down3" << endl;
}
void image_4(){
	int red;
	int blue;
	int green;



	ofstream fout;
	fout.open("output_8.ppm", fstream::app);

	for (int i = 3*x_wide / 8; i < x_wide / 2; ++i){
		for (int j = 0; j < y_heigh; ++j){
			auto pixel = get_pix(i, j);
			fout << pixel.red << " " << pixel.green << " " << pixel.blue << " ";
		}
		fout << endl;
	}

	cout << "Down4" << endl;
}
void image_5(){
	int red;
	int blue;
	int green;



	ofstream fout;
	fout.open("output_8.ppm", fstream::app);

	for (int i = x_wide / 2; i < 5*x_wide / 8; ++i){
		for (int j = 0; j < y_heigh; ++j){
			auto pixel = get_pix(i, j);
			fout << pixel.red << " " << pixel.green << " " << pixel.blue << " ";
		}
		fout << endl;
	}

	cout << "Down5" << endl;
}
void image_6(){
	int red;
	int blue;
	int green;



	ofstream fout;
	fout.open("output_8.ppm", fstream::app);

	for (int i = 5*x_wide / 8; i < 3*x_wide / 4; ++i){
		for (int j = 0; j < y_heigh; ++j){
			auto pixel = get_pix(i, j);
			fout << pixel.red << " " << pixel.green << " " << pixel.blue << " ";
		}
		fout << endl;
	}

	cout << "Down6" << endl;
}
void image_7(){
	int red;
	int blue;
	int green;



	ofstream fout;
	fout.open("output_8.ppm", fstream::app);

	for (int i = 3*x_wide / 4; i < 7*x_wide / 8; ++i){
		for (int j = 0; j < y_heigh; ++j){
			auto pixel = get_pix(i, j);
			fout << pixel.red << " " << pixel.green << " " << pixel.blue << " ";
		}
		fout << endl;
	}

	cout << "Down7" << endl;
}
void image_8(){
	int red;
	int blue;
	int green;



	ofstream fout;
	fout.open("output_8.ppm", fstream::app);

	for (int i = 7*x_wide / 8; i < x_wide; ++i){
		for (int j = 0; j < y_heigh; ++j){
			auto pixel = get_pix(i, j);
			fout << pixel.red << " " << pixel.green << " " << pixel.blue << " ";
		}
		fout << endl;
	}

	cout << "Down8" << endl;
}
//vector<int> img(x_wide*y_heigh*3);
int img[x_wide * 3][y_heigh];
void call_from_thread(int a,int b){
	int red;
	int blue;
	int green;
	/*int vidx = a*x_wide;*/
	/*ofstream fout;
	fout.open("output.ppm", fstream::app);
*/
	for (int i = a; i < b; ++i){
		for (int j = 0; j < y_heigh; ++j){
			auto pixel = get_pix(i, j);
			img[i*3][j] = pixel.red;
			img[i*3+1][j] = pixel.green;
			img[i*3+2][j] = pixel.blue;
		/*	vidx += 3;*/
			/*fout << pixel.red << " " << pixel.green << " " << pixel.blue << " ";*/
		}
		
		/*fout << endl;*/
	}

	cout << "Down" << endl;

}

int main(){




	//for (int j = 0; j < x_wide*y_heigh; ++j){
	//	
	//	fout << img[j]<<" ";
	//		if (j%x_wide == 0){
	//			fout << endl;
	//		}
	//	
	//}

	/*thread trd_1 = thread(image1);*/
	/*thread trd_2 = thread(image2);*/
	//thread trd_3 = thread(image3);
	/*thread trd_4 = thread(image4);*/
	/*	trd_1.join();*/
		//trd_2.join();
		//trd_3.join();
		//trd_4.join();
	//
	/*thread first(image1);
	thread second(image2);*/
	//thread third(image3);
	//thread fourth(image4);

	/*first.join();
	second.join();*/
	/*third.join();
	fourth.join();*/
	

	clock_t start8 = clock();
	//image_1();
	//image_2();
	//image_3();
	//image_4();
	//image_5();
	//image_6();
	//image_7();
	//image_8();
	call_from_thread(0, x_wide);
	clock_t end8 = clock();
	double time8 = (double)(end8 - start8) / CLOCKS_PER_SEC;
	cout << "8 part of no thread time: " << time8 << " second" << endl;



	const int num_threads_8 = 8;
	ofstream fout_8("output_thread_8.ppm");
	fout_8 << "P3" << endl;
	fout_8 << x_wide << " " << y_heigh << endl;
	fout_8 << "256" << endl;
	thread t_8[num_threads_8];
	clock_t start_8 = clock();
	t_8[0] = thread(call_from_thread, 0, x_wide / 8);
	t_8[1] = thread(call_from_thread, x_wide / 8, x_wide / 4);
	t_8[2] = thread(call_from_thread, x_wide / 4, 3 * x_wide / 8);
	t_8[3] = thread(call_from_thread, 3 * x_wide / 8, x_wide / 2);
	t_8[4] = thread(call_from_thread, x_wide / 2, 5 * x_wide / 8);
	t_8[5] = thread(call_from_thread, 5 * x_wide / 8, 3 * x_wide / 4);
	t_8[6] = thread(call_from_thread, 3 * x_wide / 4, 7 * x_wide / 8);
	t_8[7] = thread(call_from_thread, 7 * x_wide / 8, x_wide);

	for (int i = 0; i < num_threads_8; ++i){
		t_8[i].join();
	}
	clock_t end_8 = clock();
	for (int i = 0; i < x_wide * 3; i += 3){

		for (int j = 0; j < y_heigh; ++j){
			auto pixel = get_pix(i, j);
			fout_8 << img[i][j] << " " << img[i + 1][j] << " " << img[i + 2][j] << " ";

		}
		fout_8 << endl;
	}

	double time_8 = (double)(end_8 - start_8) / CLOCKS_PER_SEC;
	cout << "8 part of thread time: " << time_8 << " second" << endl;
	fout_8.close();


	clock_t start = clock();
	call_from_thread(0, x_wide);
	clock_t end = clock();
	double time = (double)(end - start) / CLOCKS_PER_SEC;
	cout << "4 part of no thread time: " << time << " second" << endl;




	const int num_threads = 4;
	ofstream fout("output_thread_4.ppm");
	fout << "P3" << endl;
	fout << x_wide << " " << y_heigh << endl;
	fout << "256" << endl;
	thread t[num_threads];
	clock_t start1 = clock();
	t[0] = thread(call_from_thread, 0, x_wide / 4);
	t[1] = thread(call_from_thread, x_wide / 4, x_wide / 2);
	t[2] = thread(call_from_thread, x_wide / 2, 3 * x_wide / 4);
	t[3] = thread(call_from_thread, 3 * x_wide / 4, x_wide);
	

	for (int i = 0; i < num_threads; ++i){
		t[i].join();
	}
	clock_t end1 = clock();
	for (int i = 0; i < x_wide * 3; i += 3){

		for (int j = 0; j < y_heigh; ++j){
			auto pixel = get_pix(i, j);
			fout << img[i][j] << " " << img[i + 1][j] << " " << img[i + 2][j] << " ";

		}
		fout << endl;
	}
	

	double time1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
	cout << "4 part of thread time: " << time1 << " second" << endl;
		return 0;

}












































































































































