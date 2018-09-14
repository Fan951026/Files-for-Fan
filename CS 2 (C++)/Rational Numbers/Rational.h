#ifndef RATIONAL_HPP
#define RATIONAL_HPP
#include <iostream>
class Rational {
public:
	Rational(int n = 0, int d = 1);
	Rational(Rational const&) = default; 
	operator float(); operator double(); 
	Rational& operator+=(Rational const &);
	Rational& operator-=(Rational const &);
	Rational& operator*=(Rational const &);
	Rational& operator/=(Rational const &); 
	Rational& operator=(Rational const&) = default; 
	int getNumerator()const; 
	int getDenominator()const;
	static int gcd(int a, int b){
		if (a == 0)return b;
		return gcd(b%a, a);
	}
private:
	int numerator; 
	int denominator;

};
bool operator<(Rational const &, Rational const &); 
bool operator==(Rational const &, Rational const &); 
bool operator!=(Rational const &, Rational const &); 
bool operator>(Rational const &, Rational const &); 
bool operator<=(Rational const &, Rational const &); 
bool operator>=(Rational const &, Rational const &);
Rational operator+(Rational const &, Rational const &); 
Rational operator-(Rational const &, Rational const &); 
Rational operator*(Rational const &, Rational const &); 
Rational operator/(Rational const &, Rational const &);
std::ostream & operator<<(std::ostream &, Rational const&); 
std::istream & operator>>(std::istream &, Rational &);



#endif