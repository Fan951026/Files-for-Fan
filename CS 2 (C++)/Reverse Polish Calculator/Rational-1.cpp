#include"Rational.h"

int Rational::getNumerator()const
{
	return numerator;
}

int Rational::getDenominator()const
{
	return denominator;
}

Rational::Rational(int n, int d)
{
	numerator = n;
	denominator = d;
}

Rational  operator+(Rational const & a, Rational const & b){
	int comendenona = a.getDenominator()*b.getDenominator();
	int comennumera = a.getNumerator()*b.getDenominator() + b.getNumerator()*a.getDenominator();
	int c = a.gcd(comennumera, comendenona);

	Rational answer(comennumera / c, comendenona / c);
	return answer;

}
Rational operator-(Rational const & a, Rational const & b){
	int comendenona = a.getDenominator()*b.getDenominator();
	int comennumera = a.getNumerator()*b.getDenominator() - b.getNumerator()*a.getDenominator();
	int c = a.gcd(comennumera, comendenona);
	Rational answer(comennumera / c, comendenona / c);
	return answer;
}
Rational operator*(Rational const & a, Rational const & b){
	int comendenona = a.getDenominator()*b.getDenominator();
	int comennumera = a.getNumerator()*b.getNumerator();
	int c = a.gcd(comennumera, comendenona);
	Rational answer(comennumera / c, comendenona / c);
	return answer;
}
Rational operator/(Rational const & a, Rational const & b){
	int comendenona = a.getDenominator()*b.getNumerator();
	int comennumera = a.getNumerator()*b.getDenominator();
	int c = a.gcd(comennumera, comendenona);
	Rational answer(comennumera / c, comendenona / c);
	return answer;
}
bool operator<(Rational const & a, Rational const & b){
	return a.getNumerator()*b.getDenominator() < b.getNumerator()*a.getDenominator();
}
bool operator==(Rational const & a, Rational const & b){
	return a.getNumerator()*b.getDenominator() == b.getNumerator()*a.getDenominator();
}
bool operator!=(Rational const & a, Rational const & b){
	return a.getNumerator()*b.getDenominator() != b.getNumerator()*a.getDenominator();
}
bool operator>(Rational const & a, Rational const & b){
	return a.getNumerator()*b.getDenominator() > b.getNumerator()*a.getDenominator();
}
bool operator<=(Rational const & a, Rational const & b){
	return a.getNumerator()*b.getDenominator() <= b.getNumerator()*a.getDenominator();
}
bool operator>=(Rational const & a, Rational const & b){
	return a.getNumerator()*b.getDenominator() >= b.getNumerator()*a.getDenominator();
}
Rational& Rational :: operator+=(Rational const & b){
	*this = *this + b;
	return *this;
}
Rational& Rational :: operator-=(Rational const & b){
	*this = *this - b;
	return *this;

}
Rational& Rational :: operator*=(Rational const & b){
	*this = *this * b;
	return *this;
}
Rational& Rational :: operator/=(Rational const & b){
	*this = *this / b;
	return *this;
}




std::ostream & operator<<(std::ostream &w, const Rational &f){
	
	w << f.getNumerator() << '/' << f.getDenominator();
	return w;
}
std::istream & operator>>(std::istream &w, Rational &f){
	int Numerator;
	int Denominator;
	char c;
	w >> Numerator;
	w >> c;
	if (c != '/'){
		Rational rr(Numerator);
		f = rr;
		return w;
	}

	w >> Denominator;
	Rational r(Numerator, Denominator);
	f = r;
	return w;
}