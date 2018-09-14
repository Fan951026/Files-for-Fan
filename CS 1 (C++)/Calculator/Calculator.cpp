//Visual Studio 2013;
//xuecong fan;





#include <iostream>
#include <string>
#include <math.h>//search from google

using namespace std;

void randNumber(double, double);
void randNumber1(double, double);
void randNumber2(double, double);
void randNumber3(double, double);
void randNumber4(double, double);
void randNumber5(int, int);
void randNumber6(double, double);
void randNumber7(double, double);
void randNumber8(double, double);
void randNumber9(int, int);
int main(){
	
	double num1, num2;
	char what;
	cout << "Welcome to the Calculator!\nValid operators include +,-,*,/,%,^,=,<,>,? \nTo end, enter 0 and press return\n";
	cin >> num1; cin >> what; cin >> num2;
	{
		while (num1 != 0 || num2 != 0){
			if (what == '+'){

				randNumber(num1, num2);
			}
			else if (what == '-'){
				randNumber1(num1, num2);
			}
			else if (what == '*'){
				randNumber2(num1, num2);
			}
			else if (what == '/'){
				randNumber3(num1, num2);
			}
			else if (what == '^'){
				randNumber4(num1, num2);
			}
			else if (what == '%'){
				randNumber5(num1, num2);
			}
			else if (what == '='){
				randNumber6(num1, num2);
			}
			else if (what == '<'){
				randNumber7(num1, num2);
			}
			else if (what == '>'){
				randNumber8(num1, num2);
			}
			else if (what == '?'){
				randNumber9(num1, num2);
			}
			cin >> num1; cin >> what; cin >> num2;
		}

	}
	cout << "goodbye" << endl;
	return 0;
}

void randNumber(double num1, double num2){
	
	cout << num1 + num2 << endl;
	
	
}
void randNumber1(double num1, double num2){
	
	cout << num1 - num2 << endl;

	
}
void randNumber2(double num1, double num2){
	
	cout << num1*num2 << endl;
	
	
}
void randNumber3(double num1, double num2){

	if (num2 == 0){
		cout << "Error! Can't divide by zero!" << endl;
	}
	else {
		cout << num1 / num2 << endl;
	}

}
void randNumber4(double num1, double num2){
	cout << pow(num1, num2) << endl;// search from google

}
void randNumber5(int num1,int num2){
	cout << num1%num2 << endl;
}
void randNumber6(double num1, double num2){
	if (num1 != num2){
		cout << "0" << endl;
	}
	else {
		cout << "1" << endl;
	}
	
}
void randNumber7(double num1, double num2){
	if (num1 < num2){
		cout << "1" << endl;
	}
	else{
		cout << "0" << endl;
	}

}
void randNumber8(double num1, double num2){
	if (num1 > num2){
		cout << "1" << endl;
	}
	else {
		cout << "0" << endl;
	}

}
void randNumber9(int num1, int num2){
	if (num1 > 0 && num2 > 0){
		cout << rand() % num1 + num2;
	}
	else {
		cout << "Operands cannot be negative for the ? operator!" << endl;
	}
}

