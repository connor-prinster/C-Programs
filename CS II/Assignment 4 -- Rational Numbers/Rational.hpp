#ifndef _RATIONAL_HPP_
#define _RATIONAL_HPP_

#include <fstream>

class TestCases;

class Rational
{
public:
	//default constructor;
	Rational()
	{
		m_numerator = 0;
		m_denominator = 1;
		m_name = "n/a"; //make sure it doesn't just store a pointer? The heck?
	}
	//custom constructor
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
	//functions to be defined later
	Rational add(const Rational& x);
	Rational subtract(const Rational& x);
	Rational multiply(const Rational& x);
	Rational divide(const Rational& x);
	Rational reciprocal();
	Rational power(int x);

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
};

#endif
