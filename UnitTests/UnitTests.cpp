#include "pch.h"
#include "CppUnitTest.h"
#include "../lw-2/labwork2.cpp"
#define EPSILON 0.00001

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(Task1UnitTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double answer = lw2::Task1main(-3, 0.01);
			double correctAnswer = 1.09417;
			double difference = fabs(answer - correctAnswer);
			Assert::IsTrue(difference < EPSILON);
		}

		TEST_METHOD(TestMethod2)
		{
			double answer = lw2::Task1main(0, 0.01);
			double correctAnswer = 1.0;
			double difference = fabs(answer - correctAnswer);
			Assert::IsTrue(difference < EPSILON);
		}

		TEST_METHOD(TestMethod3)
		{
			double answer = lw2::Task1main(1, 0.01);
			double correctAnswer = 0.0;
			double difference = fabs(answer - correctAnswer);
			Assert::IsTrue(difference < EPSILON);
		}

		TEST_METHOD(TestMethod4)
		{
			double answer = lw2::Task1main(3, 0.01);
			double correctAnswer = -0.23856;
			double difference = fabs(answer - correctAnswer);
			Assert::IsTrue(difference < EPSILON);
		}

		TEST_METHOD(TestMethod5)
		{
			double answer = lw2::Task1main(24, 0.01);
			double correctAnswer = -0.69011;
			double difference = fabs(answer - correctAnswer);
			Assert::IsTrue(difference < EPSILON);
		}
	};
	TEST_CLASS(Task2UnitTests)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			double x = -2;
			double y = 0;

			Assert::IsTrue(lw2::Task2main(x, y));
		}

		TEST_METHOD(TestMethod2)
		{
			double x = 0;
			double y = 2;

			Assert::IsTrue(lw2::Task2main(x, y));
		}

		TEST_METHOD(TestMethod3)
		{
			double x = 1.41422;
			double y = -1.41422;

			Assert::IsTrue(lw2::Task2main(x, y));
		}

		TEST_METHOD(TestMethod4)
		{
			double x = -3.53553;
			double y = 3.53553;

			Assert::IsTrue(lw2::Task2main(x, y));
		}

		TEST_METHOD(TestMethod5)
		{
			double x = 3.6;
			double y = 3.6;

			Assert::IsTrue(!lw2::Task2main(x, y));
		}
	};
	TEST_CLASS(Task3UnitTests)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			double a, b, c;
			a = 48;
			b = 2;
			c = -2;
			lw2::Task3main(a, b, c);
			Assert::IsTrue(a <= b && b <= c);
		}

		TEST_METHOD(TestMethod2)
		{
			double a, b, c;
			a = 0;
			b = 0;
			c = -2;
			lw2::Task3main(a, b, c);
			Assert::IsTrue(a <= b && b <= c);
		}

		TEST_METHOD(TestMethod3)
		{
			double a, b, c;
			a = 0.35421;
			b = -0.2314;
			c = 0;
			lw2::Task3main(a, b, c);
			Assert::IsTrue(a <= b && b <= c);
		}

		TEST_METHOD(TestMethod4)
		{
			double a, b, c;
			a = 0;
			b = 1;
			c = -1;
			lw2::Task3main(a, b, c);
			Assert::IsTrue(a <= b && b <= c);
		}

		TEST_METHOD(TestMethod5)
		{
			double a, b, c;
			a = 3;
			b = 2;
			c = 1;
			lw2::Task3main(a, b, c);
			Assert::IsTrue(a <= b && b <= c);
		}
	};
	TEST_CLASS(Task4UnitTests) 
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			int n = 1;
			double l = 1;
			TriangleParams triangle = lw2::Task4main(n, l);

			bool validation = (triangle.leg - 1) < EPSILON;
			validation &= (triangle.hypothenus - 1.41421) < EPSILON;
			validation &= (triangle.height - 0.70710) < EPSILON;
			validation &= (triangle.area - 1) < EPSILON;

			Assert::IsTrue(validation);
		}

		TEST_METHOD(TestMethod2)
		{
			int n = 2;
			double l = 2;
			TriangleParams triangle = lw2::Task4main(n, l);

			bool validation = (triangle.leg - 1.41421) < EPSILON;
			validation &= (triangle.hypothenus - 2) < EPSILON;
			validation &= (triangle.height - 1) < EPSILON;
			validation &= (triangle.area - 2) < EPSILON;

			Assert::IsTrue(validation);
		}

		TEST_METHOD(TestMethod3)
		{
			int n = 3;
			double l = 3;
			TriangleParams triangle = lw2::Task4main(n, l);

			bool validation = (triangle.leg - 4.24264) < EPSILON;
			validation &= (triangle.hypothenus - 6) < EPSILON;
			validation &= (triangle.height - 3) < EPSILON;
			validation &= (triangle.area - 18) < EPSILON;

			Assert::IsTrue(validation);
		}

		TEST_METHOD(TestMethod4)
		{
			int n = 4;
			double l = 4;
			TriangleParams triangle = lw2::Task4main(n, l);

			bool validation = (triangle.leg - 2) < EPSILON;
			validation &= (triangle.hypothenus - 2.82842) < EPSILON;
			validation &= (triangle.height - 1.41421) < EPSILON;
			validation &= (triangle.area - 4) < EPSILON;

			Assert::IsTrue(validation);
		}

		TEST_METHOD(TestMethod5)
		{
			int n = 1;
			double l = 0;
			TriangleParams triangle = lw2::Task4main(n, l);

			bool validation = triangle.leg < EPSILON;
			validation &= triangle.hypothenus < EPSILON;
			validation &= triangle.height < EPSILON;
			validation &= triangle.area < EPSILON;

			Assert::IsTrue(validation);
		}
	};
	TEST_CLASS(Task5UnitTests)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(lw2::Task5main(12), 4);
		}

		TEST_METHOD(TestMethod2)
		{
			Assert::AreEqual(lw2::Task5main(10), 4);
		}

		TEST_METHOD(TestMethod3)
		{
			Assert::AreEqual(lw2::Task5main(6), 2);
		}

		TEST_METHOD(TestMethod4)
		{
			Assert::AreEqual(lw2::Task5main(1), 1);
		}

		TEST_METHOD(TestMethod5)
		{
			Assert::AreEqual(lw2::Task5main(7), 3);
		}
	};
}
