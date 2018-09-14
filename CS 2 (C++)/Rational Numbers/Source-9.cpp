#include<iostream>
#include<string>
#include"Rational.h"


using namespace std;

int main(){
	int n1;
	int d1;
	int n2;
	int d2;
	cin >> n1 >> n2 >> d1 >> d2;
	Rational f1(n1, n2);
	Rational f2(d1, d2);
	Rational friction3 = f1 + f2;
	
	//cout << friction3;
	cout << n1 << " / " << n2 << " + " << d1 << " / " << d2  <<" = "<< friction3.getNumerator() << " / " << friction3.getDenominator() << endl;
	
	Rational friction4 = f1 - f2;
	cout << n1 << " / " << n2 << " - " << d1 << " / " << d2 << " = " << friction4.getNumerator() << " / " << friction4.getDenominator() << endl;
	Rational friction5 = f1 * f2;
	cout << n1 << " / " << n2 << " * " << d1 << " / " << d2 << " = " << friction5.getNumerator() << " / " << friction5.getDenominator() << endl;
	Rational friction6 = f1 / f2;
	cout << n1 << " / " << n2 << " / " << d1 << " / " << d2 << " = " << friction6.getNumerator() << " / " << friction6.getDenominator() << endl;
	

		cout << n1 << " / " << n2 << " < " << d1<<" / "<< d2 <<" is "<< (f1 < f2) << endl;
		cout << n1 << " / " << n2 << " = " << d1 << " / " <<d2<<" is "<< (f1== f2)<< endl;
		cout << n1 << " / " << n2 << " != " << d1 << " / " <<d2<< " is " << (f1 != f2) << endl;
		cout << n1 << " / " << n2 << " > " << d1 << " / " <<d2<< " is " << (f1 > f2) << endl;
		cout << n1 << " / " << n2 << " >= " << d1 << " / " <<d2<< " is " << (f1 >= f2) << endl;
		cout << n1 << " / " << n2 << " <= " << d1 << " / " <<d2<< " is " << (f1 <= f2) << endl;

		cout <<" " << endl;
		(f1 += f2);
		cout <<n1 << " / " << n2 << " += " << d1 << " / " << d2 <<" = " << f1.getNumerator() << " / " << f1.getDenominator() << endl;
		cout << f1.getNumerator() << " / " << f1.getDenominator();
		(f1 -= f2);
		
		cout << " -= " << d1 << " / " << d2 << " = " << f1.getNumerator() << " / " << f1.getDenominator() << endl;
		cout << f1.getNumerator() << " / " << f1.getDenominator();
		(f1 *= f2);
		
		cout << " *= " << d1 << " / " << d2 << " = " << f1.getNumerator() << " / " << f1.getDenominator() << endl;
		cout << f1.getNumerator() << " / " << f1.getDenominator();
		(f1 /= f2);
		cout << " /= " << d1 << " / " << d2 << " = " << f1.getNumerator() << " / " << f1.getDenominator() << endl;
		
		cout << "" << endl;
		(f1 = f2);
		cout <<d1 << " / " << d2 << " = " << f1.getNumerator() << " / " << f1.getDenominator() << endl;

		
	
	return 0;
}