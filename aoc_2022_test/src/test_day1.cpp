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
		TEST_METHOD(TestDay1Parse) {
			// setup
			Day1* day = new Day1();
			const std::string inputfilename = _PROJECTDIR + std::string("resources\\test_day1.txt");
			day->LoadFile(inputfilename);
			day->Parse();

			auto caloriesFirst = day->m_caloriesPerElf.front();
			auto caloriesLast = day->m_caloriesPerElf.back();

			// assert
			Assert::IsTrue(caloriesFirst == std::vector<int> { 20, 35, 14, 2 });
			Assert::IsTrue(caloriesLast == std::vector<int> { 4, 2, 3 });
		}

		TEST_METHOD(TestDay1SumsCorrectly) {
			// setup
			Day1* day = new Day1();
			const std::string inputfilename = _TARGETDIR + Utils::DayTypeToInputFilename<Day1>();
			day->Run(inputfilename);

			auto calories = day->SumEachElfsCalories();
			auto iterator = calories.begin();
			const int calorieFirst = *iterator;
			const int calorieSecond = *++iterator;
			const int calorieLast = calories.back();

			// assert
			Assert::AreEqual(calorieFirst, 26916);
			Assert::AreEqual(calorieSecond, 47650);
			Assert::AreEqual(calorieLast, 32326);

			// cleanup
			delete day;
		}

		TEST_METHOD(TestDay1GetsLargest) {
			// setup
			Day1* day = new Day1();
			const std::string inputfilename = _PROJECTDIR + std::string("resources\\test_day1.txt");
			day->Run(inputfilename);

			// assert
			Assert::IsTrue(day->Part1()._Equal(std::to_string(174)));

			// cleanup
			delete day;
		}
	};
}
