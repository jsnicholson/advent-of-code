#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "Days.hpp"
#include "Utils.hpp"

namespace aoc2022testing
{

	TEST_CLASS(TestingDay1)
	{
	public:	
		TEST_METHOD(TestDay1Parse)
		{
			Day1* day = new Day1();
			const std::string inputfilename = _TARGETDIR + Utils::DayTypeToInputFilename<Day1>();
			day->Run(inputfilename);

			auto iterator = day->calories.begin();
			const int calorieFirst = *iterator;
			const int calorieSecond = *++iterator;
			const int calorieLast = day->calories.back();

			Assert::AreEqual(calorieFirst, 26916);
			Assert::AreEqual(calorieSecond, 47650);
			Assert::AreEqual(calorieLast, 32326);
			delete day;
		}
	};
}
