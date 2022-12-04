#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "Days.hpp"
#include "Utils.hpp"

namespace aoc2022test
{

	TEST_CLASS(TestDay3)
	{
	public:
		TEST_METHOD(ParsesCorrectly) {
			// setup
			Day3* day = new Day3();
			const std::string inputfilename = _TARGETDIR + std::string("resources\\input_day3.txt");
			day->LoadFile(inputfilename);
			day->Parse();

			auto rucksackFirst = day->m_rucksacks.front();
			auto rucksackLast = day->m_rucksacks.back();

			// assert
			Assert::IsTrue(rucksackFirst == std::string("NGvdqJmJvpNbGRMGQgRsfgfn"));
			Assert::IsTrue(rucksackLast == std::string("VHnFjcdccjlmNVmnzmNVmCMggfqwtLLfSMwWtcWMSg"));

			// cleanup
			delete day;
		}

		TEST_METHOD(SplitBackpackIntoTwoEvenCompartments) {
			// setup
			Day3* day = new Day3();
			const std::string inputfilename = _TARGETDIR + std::string("resources\\input_day3.txt");
			day->Run(inputfilename);

			auto splitRucksackFirst = day->SplitRucksackIntoTwoEvenCompartments(day->m_rucksacks.front());
			auto splitRucksackLast = day->SplitRucksackIntoTwoEvenCompartments(day->m_rucksacks.back());

			// assert
			Assert::IsTrue(splitRucksackFirst == std::make_pair(std::string("NGvdqJmJvpNb"), std::string("GRMGQgRsfgfn")));
			Assert::IsTrue(splitRucksackLast == std::make_pair(std::string("VHnFjcdccjlmNVmnzmNVm"), std::string("CMggfqwtLLfSMwWtcWMSg")));

			// cleanup
			delete day;
		}
	};
}
