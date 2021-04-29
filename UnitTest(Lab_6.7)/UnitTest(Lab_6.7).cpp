#include "pch.h"
#include "CppUnitTest.h"

#include "../Lab_6.7/main.cpp"
#include "../Lab_6.7/Array.h"
#include "../Lab_6.7/Array.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab67
{
	TEST_CLASS(UnitTestLab67)
	{
	public:
		
		TEST_METHOD(Test_Zero)
		{
			int masuv[10]{45, 23, -8, 34, 456, 9, -9, 8, 2, -5};
			Array a = Create_Dynamic_Array(masuv, 10);
			Array b(4), c(4), d(4), f(4), g(4);

			Predicate<int>* zero = new Zero<int>();
			Assert::AreEqual(Search_End_if(&a[10], &b[0], *zero), 0);
		}
		TEST_METHOD(Test_Positive)
		{
			int masuv[10]{ 45, 23, -8, 34, 456, 9, -9, 8, 2, -5 };
			Array a = Create_Dynamic_Array(masuv, 10);
			Array b(4), c(4), d(4), f(4), g(4);

			Predicate<int>* positive = new Positive<int>();
			Assert::AreEqual(Search_End_if(&a[10], &c[0], *positive), 2);
		}
		TEST_METHOD(Test_Negative)
		{
			int masuv[10]{ 45, 23, -8, 34, 456, 9, -9, 8, 2, -5 };
			Array a = Create_Dynamic_Array(masuv, 10);
			Array b(4), c(4), d(4), f(4), g(4);

			Predicate<int>* negative = new Negative<int>();
			Assert::AreEqual(Search_End_if(&a[10], &d[0], *negative), 2);
		}
		TEST_METHOD(Test_Even)
		{
			int masuv[10]{ 45, 23, -8, 34, 456, 9, -9, 8, 2, -5 };
			Array a = Create_Dynamic_Array(masuv, 10);
			Array b(4), c(4), d(4), f(4), g(4);

			Predicate<int>* even = new Even<int>();
			Assert::AreEqual(Search_End_if(&a[10], &f[0], *even), 2);
		}
		TEST_METHOD(Test_Odd)
		{
			int masuv[10]{ 45, 23, -8, 34, 456, 9, -9, 8, 2, -5 };
			Array a = Create_Dynamic_Array(masuv, 10);
			Array b(4), c(4), d(4), f(4), g(4);

			Predicate<int>* odd = new Odd<int>();
			Assert::AreEqual(Search_End_if(&a[10], &g[0], *odd), 2);
		}
	};
}
