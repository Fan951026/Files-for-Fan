#include <iostream>
#include "InternationalPiggyBank.h"
#include <iomanip>
#include <string>
using namespace std;

int main(){

	InternationalPiggyBank piggyBank(12.34);

	piggyBank.depositMoney(0.26);
	cout << "The piggy bank has $" << fixed << setprecision(2) << piggyBank.countSavings();
	cout << " " << piggyBank.getCurrencyType() << endl;

	piggyBank.convertToCAD();
	cout << "The piggy bank has $" << piggyBank.countSavings();
	cout << " " << piggyBank.getCurrencyType() << endl;

	piggyBank.convertToEUR();
	cout << "The piggy bank has $" << piggyBank.countSavings();
	cout << " " << piggyBank.getCurrencyType() << endl;

	piggyBank.convertToMXN();
	cout << "The piggy bank has $" << piggyBank.countSavings();
	cout << " " << piggyBank.getCurrencyType() << endl;

	piggyBank.convertToJPY();
	cout << "The piggy bank has $" << piggyBank.countSavings();
	cout << " " << piggyBank.getCurrencyType() << endl;

	piggyBank.convertToUSD();
	cout << "The piggy bank has $" << piggyBank.countSavings();
	cout << " " << piggyBank.getCurrencyType() << endl;

	piggyBank.smash();
	return 0;
}
