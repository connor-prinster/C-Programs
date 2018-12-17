#ifndef _RATIONAL_HPP_
#define _RATIONAL_HPP_

#include <fstream>

class TestCases;

class Rational
{
public:
public:
	Rational();
	//default constructor;
	Rational(int num, int dem, const char* name);
	//copy constructor
	Rational(const Rational &passedInObject);
	//destructor
	~Rational();


	//overloaded
	Rational& operator=(const Rational &passedInObject);
	Rational& operator+(const Rational &passedInObject);
	Rational& operator-(const Rational &passedInObject);
	Rational& operator*(const Rational &passedInObject);
	Rational& operator/(const Rational &passedInObject);
	Rational& operator^(int x);
	//
	// vv New Functions vv
	// 
	Rational& operator+=(const Rational &passedInObject);
	Rational& operator-=(const Rational &passedInObject);
	Rational& operator*=(const Rational &passedInObject);
	Rational& operator/=(const Rational &passedInObject);
	Rational& operator^=(int x);
	Rational& operator~();
	bool operator==(const Rational &passedInObject);
	bool operator!=(const Rational &passedInObject);
	bool operator<=(const Rational &passedInObject);
	bool operator>=(const Rational &passedInObject);

	operator double();
	friend std::ostream& operator<<(std::ostream& os, const Rational& passedInObject);

	const char* getName() { return m_name; }
	void report(std::ostream& strm);

	friend TestCases;

private:
	int m_numerator;
	int	m_denominator;
	const char* m_name;

	void reduce();
	int gcd(int, int);
	void setDenominator(int denominator);

	Rational add(const Rational& x);
	Rational subtract(const Rational& x);
	Rational multiply(const Rational& x);
	Rational divide(const Rational& x);
	Rational reciprocal();
	Rational power(int x);
};

#endif
