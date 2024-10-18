#include "pch.h"
#include "CppUnitTest.h"
#include "../lw-2/labwork2.h"
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
}
