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
		TEST_METHOD(TestDay3Parse) {
			// setup
			Day3* day = new Day3();
			const std::string inputfilename = _TARGETDIR + std::string("resources\\input_day3.txt");
			day->LoadFile(inputfilename);
			day->Parse();

			auto rucksackFirst = day->m_rucksacks.front();
			auto rucksackLast = day->m_rucksacks.back();

			// assert
			Assert::IsTrue(rucksackFirst == std::make_pair(std::string("NGvdqJmJvpNb"),std::string("GRMGQgRsfgfn")));
			Assert::IsTrue(rucksackLast == std::make_pair(std::string("VHnFjcdccjlmNVmnzmNVm"), std::string("CMggfqwtLLfSMwWtcWMSg")));

			// cleanup
			delete day;
		}
	};
}
