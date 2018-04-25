#include <iostream>

#include "Rational.hpp"
#include "TestCases.hpp"

void report(Rational a, std::string operation, Rational b, Rational r)
{
	using namespace std;

	cout << "first " << operation << " second" << endl;
	a.report(cout);
	cout << " " << operation << " ";
	b.report(cout);
	cout << " = ";
	r.report(cout);
	cout << endl << endl;
}

void report(Rational a, std::string operation, Rational r)
{
	using namespace std;

	cout << "first " << operation << endl;
	r.report(cout);
	cout << endl << endl;
}

int main()
{
	using namespace std;
	TestCases::runTestCases();

	Rational c(1, 3, "first");
	Rational d(7, 9, "second");
	Rational x;

	std::cout << "-- Member Functions --" << std::endl << std::endl;
	
	report(c, "+", d, c.add(d));
	report(c, "-", d, c.subtract(d));
	report(c, "*", d, c.multiply(d));
	report(c, "/", d, c.divide(d));
	report(c, "reciprocal", c.reciprocal());
	report(c, "to power of 4", c.power(4));

	cout << "Press 'enter' to exit the program...";
	cin.get(); //allows the program to stop :);

	return 0;
}
