#ifndef _TEST_CASES_HPP
#define _TEST_CASES_HPP

#include <functional>
#include <string>
#include <vector>
#include <iostream>

class TestCases
{
	public:
		static void runTestCases();

		static bool testCopyConstructorTest();
		static bool testAssignmentOperatorTest();
		static bool testAddCase1();
		static bool testSubtractCase1();
		static bool testDivideCase1();
		static bool testMultiplyCase1();
		static bool testReciprocalCase1();
		static bool testPowerCase1();
		static bool testGetNameCase1();

	private:
		static void runTest(std::function<bool(void)> testCase, std::string label);

};

template <typename T>
bool _expect_eq(T expected, T actual, const char* pFileName, int line)
{
	bool ret = true;

	if (expected != actual)
	{
		std::cout << "Expected " << expected << " == " << actual << " at " << pFileName << ":" << line << std::endl;
		ret = false;
	}
	return ret;
}


template <typename T>
bool _expect_gt(T x, T y, const char* pFileName, int line)
{
	bool ret = true;

	if (x <= y)
	{
		std::cout << "Expected that " << x << " > " << y << " at " << pFileName << ":" << line << std::endl;
		ret = false;
	}
	return ret;
}

#define EXPECT_EQ(x, y) _expect_eq(x, y, __FILE__, __LINE__)
#define EXPECT_GT(x, y) _expect_gt(x, y, __FILE__, __LINE__)

#endif // _TEST_CASES_HPP
