#include <iostream>

using namespace std;

int main(){
	double age;


	cout << "How old are you?";
	cin >> age;




	if (age<16){
		cout << "You can't drive." << endl;
	}
	else if (age <= 17){
		cout << "You can drive but not vote." << endl;
	}
	else if (age <= 24){
		cout << "You can vote but not rent a car." << endl;
	}
	else {
		cout << "You can do pretty much anything." << endl;
	}








	return 0;
}