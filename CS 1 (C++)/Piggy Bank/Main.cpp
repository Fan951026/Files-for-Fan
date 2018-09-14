#include <iostream>
#include <string>
#include "PiggyBank.h"

using namespace std;

int main(){

	cout << "wellcome the PiggyBank! " << endl;
	PiggyBank PiggyBank;


	PiggyBank.setmoney(15);
	cout << "You deposit $ " << PiggyBank.getmoney() << endl;
	cout<<"your saving account now have $ " << PiggyBank.getsaving() << endl;
	PiggyBank.getcheck();
	PiggyBank.setmoney1(23.5);
	cout << "You deposit $ " << PiggyBank.getmoney1() << endl;
	cout << "your saving account now have $ " << PiggyBank.getsaving() << endl;
	PiggyBank.getcheck();
	PiggyBank.setmoney2(33.57);
	cout << "You deposit $ " << PiggyBank.getmoney2() << endl;
	cout << "your saving account now have $ " << PiggyBank.getsaving() << endl;
	PiggyBank.getcheck();
	PiggyBank.setmoney3(54);
	cout << "You deposit $ " << PiggyBank.getmoney3() << endl;
	cout << "your saving account now have $ " << PiggyBank.getsaving() << endl;

	PiggyBank.setmoney4(12);
	PiggyBank.getcheck();
	cout << "You deposit $ " << PiggyBank.getmoney4() << endl;
	cout << "your saving account now have $ " << PiggyBank.getsaving() << endl;
	PiggyBank.~PiggyBank();
	PiggyBank.getcheck();
	PiggyBank.getsmash();
	PiggyBank.getstart();


	


	return 0;
}