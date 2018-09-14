#include "HashTableQ.h"
#include "HashTableS.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cmath>
void HashS1(){
	HashTableS q(66);
	ifstream fin;
	fin.open("zipcodes.csv");
	string zipcode = "";
	string latitude = "";
	string longtitude = "";

	for (int i = 0; i < 20; ++i){

		getline(fin, zipcode, ',');
		getline(fin, latitude, ',');
		getline(fin, longtitude);


		q.Insert(zipcode, stod(latitude), stod(longtitude));

	}
	q.PrintTableEntry();

	while (true){
		getline(fin, zipcode, ',');
		getline(fin, latitude, ',');
		getline(fin, longtitude);
		if (fin.eof()) break;
		q.Insert(zipcode, stod(latitude), stod(longtitude));
	}
	cout << q.findlength() << endl;


	ifstream fin1;
	fin1.open("searchzip.txt");
	ofstream fin2;
	fin2.open("validzip.txt");
	string zipcode1;
	while (true){
		getline(fin1, zipcode1);
		if (fin1.eof()) break;
		if (q.Search(zipcode1) == true) {
			fin2 << zipcode1 << endl;
		}
	}
	

	ifstream fin3;
	fin3.open("validzip.txt");
	string zip1;
	string zip2;
	getline(fin3, zip2);
	double sum = 0;
	int start = clock();
	while (true){
		zip1 = zip2;
		getline(fin3, zip2);
		if (zip2.empty()) break;
		sum += q.ComputeDistance(zip1, zip2);

	}
	int end = clock();
	fin2 << "total time: " << (end - start) / double(CLOCKS_PER_SEC) * 1000 << " milliseconds" << endl;
	fin2 << "total distance:" << sum << endl;

}
void HashS2(){
	HashTableS q(50);
	ifstream fin;
	fin.open("zipcodes.csv");
	string zipcode = "";
	string latitude = "";
	string longtitude = "";

	for (int i = 0; i < 20; ++i){

		getline(fin, zipcode, ',');
		getline(fin, latitude, ',');
		getline(fin, longtitude);


		q.Insert(zipcode, stod(latitude), stod(longtitude));

	}
	q.PrintTableEntry();

	while (true){
		getline(fin, zipcode, ',');
		getline(fin, latitude, ',');
		getline(fin, longtitude);
		if (fin.eof()) break;
		q.Insert(zipcode, stod(latitude), stod(longtitude));
	}
	cout << q.findlength() << endl;


	ifstream fin1;
	fin1.open("searchzip.txt");
	ofstream fin2;
	fin2.open("validzip.txt");
	string zipcode1;
	while (true){
		getline(fin1, zipcode1);
		if (fin1.eof()) break;
		if (q.Search(zipcode1) == true) {
			fin2 << zipcode1 << endl;
		}
	}
	

	ifstream fin3;
	fin3.open("validzip.txt");
	string zip1;
	string zip2;
	getline(fin3, zip2);
	double sum = 0;
	int start = clock();
	while (true){
		zip1 = zip2;
		getline(fin3, zip2);
		if (zip2.empty()) break;
		sum += q.ComputeDistance(zip1, zip2);

	}
	int end = clock();
	fin2 << "total time: " << (end - start) / double(CLOCKS_PER_SEC) * 1000 << " milliseconds" << endl;
	fin2 << "total distance:" << sum << endl;

}
void HashS3(){
	HashTableS q(40);
	ifstream fin;
	fin.open("zipcodes.csv");
	string zipcode = "";
	string latitude = "";
	string longtitude = "";

	for (int i = 0; i < 20; ++i){

		getline(fin, zipcode, ',');
		getline(fin, latitude, ',');
		getline(fin, longtitude);


		q.Insert(zipcode, stod(latitude), stod(longtitude));

	}
	q.PrintTableEntry();

	while (true){
		getline(fin, zipcode, ',');
		getline(fin, latitude, ',');
		getline(fin, longtitude);
		if (fin.eof()) break;
		q.Insert(zipcode, stod(latitude), stod(longtitude));
	}
	cout << q.findlength() << endl;


	ifstream fin1;
	fin1.open("searchzip.txt");
	ofstream fin2;
	fin2.open("validzip.txt");
	string zipcode1;
	while (true){
		getline(fin1, zipcode1);
		if (fin1.eof()) break;
		if (q.Search(zipcode1) == true) {
			fin2 << zipcode1 << endl;
		}
	}


	ifstream fin3;
	fin3.open("validzip.txt");
	string zip1;
	string zip2;
	getline(fin3, zip2);
	double sum = 0;
	int start = clock();
	while (true){
		zip1 = zip2;
		getline(fin3, zip2);
		if (zip2.empty()) break;
		sum += q.ComputeDistance(zip1, zip2);

	}
	int end = clock();
	fin2 << "total time: " << (end - start) / double(CLOCKS_PER_SEC) * 1000 << " milliseconds" << endl;
	fin2 << "total distance:" << sum << endl;

}
void HashS4(){
	HashTableS q(10);
	ifstream fin;
	fin.open("zipcodes.csv");
	string zipcode = "";
	string latitude = "";
	string longtitude = "";

	for (int i = 0; i < 20; ++i){

		getline(fin, zipcode, ',');
		getline(fin, latitude, ',');
		getline(fin, longtitude);


		q.Insert(zipcode, stod(latitude), stod(longtitude));

	}
	q.PrintTableEntry();

	while (true){
		getline(fin, zipcode, ',');
		getline(fin, latitude, ',');
		getline(fin, longtitude);
		if (fin.eof()) break;
		q.Insert(zipcode, stod(latitude), stod(longtitude));
	}
	cout << q.findlength() << endl;


	ifstream fin1;
	fin1.open("searchzip.txt");
	ofstream fin2;
	fin2.open("validzip.txt");
	string zipcode1;
	while (true){
		getline(fin1, zipcode1);
		if (fin1.eof()) break;
		if (q.Search(zipcode1) == true) {
			fin2 << zipcode1 << endl;
		}
	}


	ifstream fin3;
	fin3.open("validzip.txt");
	string zip1;
	string zip2;
	getline(fin3, zip2);
	double sum = 0;
	int start = clock();
	while (true){
		zip1 = zip2;
		getline(fin3, zip2);
		if (zip2.empty()) break;
		sum += q.ComputeDistance(zip1, zip2);

	}
	int end = clock();
	fin2 << "total time: " << (end - start) / double(CLOCKS_PER_SEC) * 1000 << " milliseconds" << endl;
	fin2 << "total distance:" << sum << endl;

}
void HashQ1(){
	ifstream fin;

	fin.open("zipcodes.csv");
	string zipcode = "";
	string latitude = "";
	string longtitude = "";
	int number = 0;
	while (true){
		number += 1;
	}
	fin.close();
	ifstream fin5;

	fin5.open("zipcodes.csv");
	HashTableQ q(number * 10 / 3);
	
	while (true){
		getline(fin5, zipcode, ',');
		getline(fin5, latitude, ',');
		getline(fin5, longtitude);
		if (fin5.eof()) break;
		q.Insert(zipcode, stod(latitude), stod(longtitude));
	
	}


	ifstream fin1;
	fin1.open("searchzip.txt");
	ofstream fin2;
	fin2.open("validzip.txt");
	string zipcode1;
	while (true){
		getline(fin1, zipcode1);
		if (fin1.eof()) break;
		if (q.Search(zipcode1) == true) {
			fin2 << zipcode1 << endl;
		}
	}


	ifstream fin3;
	fin3.open("validzip.txt");
	string zip1;
	string zip2;
	getline(fin3, zip2);
	double sum = 0;
	int start = clock();
	while (true){
		zip1 = zip2;
		getline(fin3, zip2);
		if (zip2.empty()) break;
		sum += q.ComputeDistance(zip1, zip2);

	}
	int end = clock();
	fin2 << "total time: " << (end - start) / double(CLOCKS_PER_SEC) * 1000 << " milliseconds" << endl;
	fin2 << "total distance:" << sum << endl;

}
void HashQ2(){
	ifstream fin;

	fin.open("zipcodes.csv");
	string zipcode = "";
	string latitude = "";
	string longtitude = "";
	int number = 0;
	while (true){
		number += 1;
	}
	fin.close();
	ifstream fin5;

	fin5.open("zipcodes.csv");
	HashTableQ q(number * 10 / 4);

	while (true){
		getline(fin5, zipcode, ',');
		getline(fin5, latitude, ',');
		getline(fin5, longtitude);
		if (fin5.eof()) break;
		q.Insert(zipcode, stod(latitude), stod(longtitude));

	}


	ifstream fin1;
	fin1.open("searchzip.txt");
	ofstream fin2;
	fin2.open("validzip.txt");
	string zipcode1;
	while (true){
		getline(fin1, zipcode1);
		if (fin1.eof()) break;
		if (q.Search(zipcode1) == true) {
			fin2 << zipcode1 << endl;
		}
	}


	ifstream fin3;
	fin3.open("validzip.txt");
	string zip1;
	string zip2;
	getline(fin3, zip2);
	double sum = 0;
	int start = clock();
	while (true){
		zip1 = zip2;
		getline(fin3, zip2);
		if (zip2.empty()) break;
		sum += q.ComputeDistance(zip1, zip2);

	}
	int end = clock();
	fin2 << "total time: " << (end - start) / double(CLOCKS_PER_SEC) * 1000 << " milliseconds" << endl;
	fin2 << "total distance:" << sum << endl;

}
void HashQ3(){
	ifstream fin;

	fin.open("zipcodes.csv");
	string zipcode = "";
	string latitude = "";
	string longtitude = "";
	int number = 0;
	while (true){
		number += 1;
	}
	fin.close();
	ifstream fin5;

	fin5.open("zipcodes.csv");
	HashTableQ q(number * 10 / 5);

	while (true){
		getline(fin5, zipcode, ',');
		getline(fin5, latitude, ',');
		getline(fin5, longtitude);
		if (fin5.eof()) break;
		q.Insert(zipcode, stod(latitude), stod(longtitude));

	}


	ifstream fin1;
	fin1.open("searchzip.txt");
	ofstream fin2;
	fin2.open("validzip.txt");
	string zipcode1;
	while (true){
		getline(fin1, zipcode1);
		if (fin1.eof()) break;
		if (q.Search(zipcode1) == true) {
			fin2 << zipcode1 << endl;
		}
	}


	ifstream fin3;
	fin3.open("validzip.txt");
	string zip1;
	string zip2;
	getline(fin3, zip2);
	double sum = 0;
	int start = clock();
	while (true){
		zip1 = zip2;
		getline(fin3, zip2);
		if (zip2.empty()) break;
		sum += q.ComputeDistance(zip1, zip2);

	}
	int end = clock();
	fin2 << "total time: " << (end - start) / double(CLOCKS_PER_SEC) * 1000 << " milliseconds" << endl;
	fin2 << "total distance:" << sum << endl;

}


int main(){


	cout << "/*" << "Driver code for Assignment 5: Hash Tables" << "\n" << "Created by: xuecong fan" << "*/" << endl;
	HashTableS HashTableS(11);
	HashTableS.PrintTableEntry();
	HashTableS.Insert("00501", 40.81, -73.04);
	HashTableS.Insert("00544", 40.81, -73.04);
	HashTableS.Insert("00601", 18.16, -66.72);
	HashTableS.Insert("00602", 18.38, -67.18);
	HashTableS.Insert("00603", 18.43, -67.15);
	HashTableS.Insert("00604", 18.43, -67.15);
	HashTableS.Insert("00605", 18.43, -67.15);
	HashTableS.Insert("00606", 18.18, -66.98);
	HashTableS.Insert("00610", 18.28, -67.14);
	HashTableS.Insert("00611", 18.28, -66.79);

	HashTableS.PrintTableEntry();
	cout << HashTableS.Search("00601") << endl;
	cout << HashTableS.Search("84321") << endl;
	cout << HashTableS.ComputeDistance("00601", "00611") << endl;
	cout << HashTableS.CountTableEntry(1) << endl;
	cout << HashTableS.CountTableEntry(9) << endl;

	cout << "Quadratic one" << endl;

	HashTableQ HashTableQ(11);
	HashTableQ.PrintTableEntry();
	HashTableQ.Insert("00501", 40.81, -73.04);
	HashTableQ.Insert("00544", 40.81, -73.04);
	HashTableQ.Insert("00601", 18.16, -66.72);
	HashTableQ.Insert("00602", 18.38, -67.18);
	HashTableQ.Insert("00603", 18.43, -67.15);
	HashTableQ.Insert("00604", 18.43, -67.15);
	HashTableQ.Insert("00605", 18.43, -67.15);
	HashTableQ.Insert("00606", 18.18, -66.98);
	HashTableQ.Insert("00610", 18.28, -67.14);
	HashTableQ.Insert("00611", 18.28, -66.79);
	HashTableQ.PrintTableEntry();
	HashTableQ.Remove("00501");
	HashTableQ.Remove("84321");
	HashTableQ.Insert("11724", 40.86, -73.44);
	HashTableQ.Insert("11726", 40.67, -73.39);

	HashTableQ.PrintTableEntry();
	cout << HashTableQ.Search("00601") << endl;
	cout << HashTableQ.Search("84321") << endl;
	cout << HashTableQ.Search("00544") << endl;
	cout << HashTableQ.ComputeDistance("00601", "00605") << endl;

	int input;
	cout << "HashS 0.3 enter 1\n";
	cout << "HashS 0.4 enter 2\n";
	cout << "HashS 0.5 enter 3\n";
	cout << "HashS 2 enter 4\n";
	cout << "HashQ 0.3 enter 5\n";
	cout << "HashQ 0.4 enter 6\n";
	cout << "HashQ 0.5 enter 7\n";
	cin >> input;
	switch (input)
	{
	case 1:
		HashS1();
		break;
	case 2:
		HashS2();
		break;
	case 3:
		HashS3();
		break;
	case 4:
		HashS4();
		break;
	case 5:
		HashQ1();
		break;
	case 6:
		HashQ2();
		break;
	case 7:
		HashQ3();
		break;
	default:
		break;
	}

	







	
	






	return 0;
}
