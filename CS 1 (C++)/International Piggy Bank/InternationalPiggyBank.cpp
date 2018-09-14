#include "InternationalPiggyBank.h"
#include <string>

InternationalPiggyBank::InternationalPiggyBank(double L){
	Type = USD;
	smashs = false;
	Bank = L;
}
double InternationalPiggyBank::countSavings(){

	return Bank ;
	
}
void InternationalPiggyBank::depositMoney(double q){
	
	if (smashs){
		cout << "don't put in money, its broken!" << endl;
	}
	else if (q < 0){
		cout << "wrong number!" << endl;
	}
	else {
		Bank += q;
	}
}

void InternationalPiggyBank::convertToUSD(){
	if (Type == USD){
		Bank = Bank / USDCONVRATE* USDCONVRATE;
	}
	else if (Type == EUR){
		Bank = Bank / EURCONVRATE*USDCONVRATE;
	}
	else if (Type == CAD){
		Bank = Bank / CADCONVRATE*USDCONVRATE;
	}
	else if (Type == MXN){
		Bank = (Bank / MXNCONVRATE) *USDCONVRATE;
	}
	else if (Type == JPY){
		Bank = (Bank / JPYCONVRATE)*USDCONVRATE;
	}
	Type = USD;
}

void InternationalPiggyBank::convertToCAD(){
	if (Type == USD){
		Bank = Bank / USDCONVRATE* CADCONVRATE;
	}
	else if (Type == EUR){
		Bank = Bank / EURCONVRATE*CADCONVRATE;
	}
	else if (Type == CAD){
		Bank = Bank / CADCONVRATE*CADCONVRATE;
	}
	else if (Type == MXN){
		Bank = (Bank / MXNCONVRATE) *CADCONVRATE;
	}
	else if (Type == JPY){
		Bank = (Bank / JPYCONVRATE)*CADCONVRATE;
	}
	Type =CAD;
}

void InternationalPiggyBank::convertToEUR(){

	if (Type == USD){
		Bank = Bank / USDCONVRATE* EURCONVRATE;
	}
	else if (Type == EUR){
		Bank = Bank / EURCONVRATE*EURCONVRATE;
	}
	else if (Type == CAD){
		Bank = Bank / CADCONVRATE*EURCONVRATE;
	}
	else if (Type == MXN){
		Bank = (Bank / MXNCONVRATE) *EURCONVRATE;
	}
	else if (Type == JPY){
		Bank = Bank / JPYCONVRATE *EURCONVRATE;
	}
	Type = EUR;
}

void InternationalPiggyBank::convertToMXN(){
	if (Type == USD){
		Bank = Bank / USDCONVRATE* MXNCONVRATE;
	}
	else if (Type == EUR){
		Bank = Bank / EURCONVRATE*MXNCONVRATE;
	}
	else if (Type == CAD){
		Bank = Bank / CADCONVRATE*MXNCONVRATE;
	}
	else if (Type == MXN){
		Bank = (Bank / MXNCONVRATE) *MXNCONVRATE;
	}
	else if (Type == JPY){
		Bank = Bank / JPYCONVRATE *MXNCONVRATE;
	}
	Type = MXN;
}

void InternationalPiggyBank::convertToJPY(){

	if (Type == USD){
		Bank = Bank / USDCONVRATE*JPYCONVRATE;
	}
	else if (Type == EUR){
		Bank = Bank / EURCONVRATE*JPYCONVRATE;
	}
	else if (Type == CAD){
		Bank = Bank / CADCONVRATE*JPYCONVRATE;
	}
	else if (Type == MXN){
		Bank = (Bank / MXNCONVRATE) *JPYCONVRATE;
	}
	else if (Type == JPY){
		Bank = Bank / JPYCONVRATE *JPYCONVRATE;
	}
	Type = JPY;
}

string InternationalPiggyBank::getCurrencyType(){
	
	if (Type == USD){
		return "USD";
	}
	else if (Type == EUR){
		return "EUR";
	}
	else if (Type == CAD){
		return "CAD";
	}
	else if (Type == MXN){
		return "MXN";
	}
	else if (Type == JPY){
		return "JPY";
	}
}
double InternationalPiggyBank::smash(){
	smashs = true;
	return Bank;
}

InternationalPiggyBank::~InternationalPiggyBank(){
	cout << "It's broken!" << endl;
}


