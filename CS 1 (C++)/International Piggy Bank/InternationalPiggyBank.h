#ifndef INTERNATIONALPIGGYBANK_H
#define INTERNATIONALPIGGYBANK_H
#include <string>
#include <iostream>
using namespace std;
class InternationalPiggyBank
{
public:
	InternationalPiggyBank(double);
	double countSavings();
	void setcountSavings(double);

	void depositMoney(double);
	void convertToUSD();

	void convertToCAD();

	void convertToEUR();

	void convertToMXN();

	void convertToJPY();

	string getCurrencyType();
	double setgetCurrencyType();
	~InternationalPiggyBank();
	double smash();

private:
	double S;
	
	double Bank;

	bool smashs;
	

	enum CurrencyType { USD, EUR, CAD, MXN, JPY };
	CurrencyType Type;
	const double USDCONVRATE = 1.0;

	const double EURCONVRATE = 0.92; // 0.92 EUR = 1 USD

	const double CADCONVRATE = 1.25; // 1.25 CAD = 1 USD

	const double MXNCONVRATE = 15.12; // 15.12 MXN = 1 USD

	const double JPYCONVRATE = 119.19; // 119.19 JPY = 1 USD

};
#endif;
