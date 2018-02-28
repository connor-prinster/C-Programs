#include <iostream>

#include "Rational.hpp"
#include "TestCases.hpp"


int main()
{
	TestCases::runTestCases();

	Rational c(1, 3, "first");
	Rational d(7, 9, "second");
	Rational x;

	//
	// -- Use the overloaded operators --
	//

	std::cout << "-- Mathematical Operators --" << std::endl << std::endl;

	x = c + d;
	std::cout << c.getName() << " + " << d.getName() << std::endl;
	std::cout << c << " + " << d << " = " << x << std::endl;
	std::cout << x << " = " << static_cast<double>(x) << std::endl << std::endl;

	x = c - d;
	std::cout << c.getName() << " - " << d.getName() << std::endl;
	std::cout << c << " - " << d << " = " << x << std::endl;
	std::cout << x << " = " << static_cast<double>(x) << std::endl << std::endl;

	x = c * d;
	std::cout << c.getName() << " * " << d.getName() << std::endl;
	std::cout << c << " * " << d << " = " << x << std::endl;
	std::cout << x << " = " << static_cast<double>(x) << std::endl << std::endl;

	x = c / d;
	std::cout << c.getName() << " / " << d.getName() << std::endl;
	std::cout << c << " / " << d << " = " << x << std::endl;
	std::cout << x << " = " << static_cast<double>(x) << std::endl << std::endl;

	x = ~c;
	std::cout << "reciprocal of " << c << " = " << x << std::endl;
	std::cout << x << " = " << static_cast<double>(x) << std::endl << std::endl;

	x = c ^ 4;
	std::cout << c.getName() << " ^ " << 4 << std::endl;
	std::cout << c << " ^ 4" << " = " << x << std::endl;
	std::cout << x << " = " << static_cast<double>(x) << std::endl << std::endl;

	//
	// -- Using the relational operators --
	//
	Rational equal1(1, 2, "1 / 2");
	Rational equal2(2, 4, "2 / 4");
	Rational small(1, 10, "1 / 10");
	Rational big(10, 1, "10 / 1");

	std::cout << "-- Relational Operators --" << std::endl << std::endl;
	if (equal1 == equal2)
	{
		std::cout << equal1.getName() << " equals " << equal2.getName() << std::endl << std::endl;
	}
	if (small != big)
	{
		std::cout << small.getName() << " not equal to " << big.getName() << std::endl << std::endl;
	}
	if (small <= big)
	{
		std::cout << small.getName() << " smaller than " << big.getName() << std::endl << std::endl;
	}
	if (big >= small)
	{
		std::cout << big.getName() << " greater than " << small.getName() << std::endl << std::endl;
	}

	std::cout << "Hit the 'ENTER' key to exit the program...";
	std::cin.get();

	return 0;
}
