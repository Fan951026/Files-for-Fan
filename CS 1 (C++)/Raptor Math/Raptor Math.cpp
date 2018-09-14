#include <iostream>
#include <string>

using namespace std;

int main()
{
	double meters;
	double velociraptor;
	double people;


	cout << "How far away is the raptor in meters?" << endl;
	cout << "meter between peple and velociraptor: ";
	cin >> meters;
	cout << " top velociraptor speed: ";
	cin >> velociraptor;
	cout << "top people speed: ";
	cin >> people;
	cout << "you will remain alive for " << meters / (velociraptor - people) << "secend." << " And " << people *(meters / (velociraptor - people)) << "meters." << endl;









	return 0;
}