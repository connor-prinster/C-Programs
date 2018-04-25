#include "Rational.hpp"
#include <cstring>
#include <cmath>

using namespace std;

//constructor
Rational::Rational(int num, int den, const char* name)
{
	m_numerator = num;
	m_denominator = den;
	m_name = name;
}

//copy constructor
Rational::Rational(const Rational &passedInObject)
{
	this->m_numerator = passedInObject.m_numerator;
	this->m_denominator = passedInObject.m_denominator;
	char* copy = new char[strlen(passedInObject.m_name) + 1];
	int size = strlen(passedInObject.m_name) + 1;
	strcpy_s(copy, size, passedInObject.m_name);
}

Rational::~Rational()
{

}

Rational& Rational::operator=(const Rational& passedInObject)
{
	if (this == &passedInObject)
	{
		return *this;
	}
	this->m_numerator = passedInObject.m_numerator;
	this->m_denominator = passedInObject.m_denominator;

	return *this;
}

Rational& Rational::operator+(const Rational& passedInObject)
{
	Rational* addOpp = new Rational();
	Rational* thisCopy = new Rational(*this);
	Rational* passCopy = new Rational(passedInObject);

	int commonDen = thisCopy->m_denominator*passCopy->m_denominator;

	thisCopy->m_numerator *= passCopy->m_denominator;
	passCopy->m_numerator *= thisCopy->m_denominator;
	thisCopy->m_denominator = commonDen;
	passCopy->m_denominator = commonDen;

	addOpp->m_numerator = thisCopy->m_numerator + passCopy->m_numerator;
	addOpp->m_denominator = commonDen;

	addOpp->reduce();

	return *addOpp;
}

Rational& Rational::operator-(const Rational& passedInObject)
{
	Rational* subOpp = new Rational();
	Rational* thisCopy = new Rational(*this);
	Rational* passCopy = new Rational(passedInObject);

	int commonDen = thisCopy->m_denominator*passCopy->m_denominator;

	thisCopy->m_numerator *= passCopy->m_denominator;
	passCopy->m_numerator *= thisCopy->m_denominator;
	thisCopy->m_denominator = commonDen;
	passCopy->m_denominator = commonDen;

	subOpp->m_numerator = thisCopy->m_numerator - passCopy->m_numerator;
	subOpp->m_denominator = commonDen;

	subOpp->reduce();

	return *subOpp;
}

Rational& Rational::operator*(const Rational& passedInObject)
{
	Rational* multOpp = new Rational();
	multOpp->m_numerator = this->m_numerator * passedInObject.m_numerator;
	multOpp->m_denominator = this->m_denominator * passedInObject.m_denominator;

	multOpp->reduce();

	return *multOpp;
}

Rational& Rational::operator/(const Rational& passedInObject)
{
	Rational* divOpp = new Rational();
	divOpp->m_numerator = this->m_numerator * passedInObject.m_denominator;
	divOpp->m_denominator = this->m_denominator * passedInObject.m_numerator;

	divOpp->reduce();

	return *divOpp;
}

Rational& Rational::operator^(int x)
{
	Rational* pwrOpp = new Rational();
	int origNum = this->m_numerator;
	int origDen = this->m_denominator;

	int adjNum = origNum;
	int adjDen = origDen;

	for (int i = 0; i < x-1; i++)
	{
		adjNum = adjNum * origNum;
		adjDen = adjDen * origDen;
	}

	pwrOpp->m_numerator = adjNum;
	pwrOpp->m_denominator = adjDen;

	pwrOpp->reduce();

	return *pwrOpp;
}

void Rational::report(std::ostream& strm)
{
	strm << m_numerator << " / " << m_denominator;
}


//--------------------------//
//	Mathematical Operators	//
//--------------------------//
Rational Rational::add(const Rational& x)
{
	Rational returnAdd = Rational();
	returnAdd = this->operator+(x);

	return returnAdd;
}

Rational Rational::subtract(const Rational& x)
{
	Rational returnSub = Rational();
	returnSub = this->operator-(x);

	return returnSub;
}

Rational Rational::multiply(const Rational& x)
{
	Rational returnMult = Rational();
	returnMult = this->operator*(x);

	return returnMult;
}

Rational Rational::divide(const Rational& x)
{
	Rational returnDiv = Rational();
	returnDiv = this->operator/(x);

	return returnDiv;
}

Rational Rational::reciprocal()
{
	Rational returnRec = Rational();
	returnRec.m_numerator = this->m_denominator;
	returnRec.m_denominator = this->m_numerator;

	return returnRec;
}

Rational Rational::power(int x)
{
	Rational returnPwr = Rational();
	returnPwr = this->operator^(x);

	return returnPwr;
}

//#NOT MINE
//========================================================================
//========================================================================
//-------------------------------------------------------------------
//
// Sets denominator to an integer value. If the denominator is negative
// then it is changed to a positive value and the numerator of the
// Rational is changed to a negative to avoid negatives in the denominator.
// It also calls the reduce function incase a simplification can be made.
//
//-------------------------------------------------------------------
void Rational::setDenominator(int b)
{
	if (b == 0)	// Prevents 0 denominators
	{
		//
		// TODO: We can eventually do something better, but doing this for now
		m_denominator = 1;
	}
	else if (b < 0)  // Corrects negative denominators
	{
		m_numerator = -1 * m_numerator;
		m_denominator = -1 * b;
		reduce();
	}
	else
	{
		m_denominator = b;
		reduce();
	}
}

//-------------------------------------------------------------------
//
// Reduces Rationals to their simplified form by dividing the num and den by
// the greatest common divisor
//
//-------------------------------------------------------------------
void Rational::reduce()
{
	int commonDivisor = gcd(abs(m_numerator), m_denominator);
	m_numerator = (m_numerator / commonDivisor);
	m_denominator = (m_denominator / commonDivisor);
}

//-------------------------------------------------------------------
//
// Finds the gcd of two integers
//
//-------------------------------------------------------------------
int Rational::gcd(int numerator, int denominator)
{
	if (denominator == 0)
	{
		return numerator;
	}

	return gcd(denominator, numerator % denominator);
}
//========================================================================
//========================================================================