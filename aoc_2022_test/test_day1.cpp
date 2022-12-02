#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "Days.hpp"
#include "Utils.hpp"

namespace aoc2022test
{

	TEST_CLASS(TestDay1)
	{
	public:	
		TEST_METHOD(TestDay1Parse)
		{
			// setup
			Day1* day = new Day1();
			const std::string inputfilename = _TARGETDIR + Utils::DayTypeToInputFilename<Day1>();
			day->LoadFile(inputfilename);
			day->Parse();

			auto iterator = day->calories.begin();
			const int calorieFirst = *iterator;
			const int calorieSecond = *++iterator;
			const int calorieLast = day->calories.back();

			// assert
			Assert::AreEqual(calorieFirst, 26916);
			Assert::AreEqual(calorieSecond, 47650);
			Assert::AreEqual(calorieLast, 32326);

			// cleanup
			delete day;
		}

		TEST_METHOD(TestDay1GetsLargest)
		{
			// setup
			Day1* day = new Day1();
			const std::string inputfilename = _TARGETDIR + std::string("resources\\test_day1.txt");
			day->Run(inputfilename);

			// assert
			Assert::AreEqual(day->Part1(), 174);

			// cleanup
			delete day;
		}
	};
}
