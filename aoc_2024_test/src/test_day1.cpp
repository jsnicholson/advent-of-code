#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "Days.hpp"
#include "Utils.hpp"

namespace aoc2024test
{

	TEST_CLASS(TestDay1)
	{
	public:	
		TEST_METHOD(TestDay1Parse) {
			Day1* day = new Day1();
			const std::string inputfilename = _PROJECTDIR + std::string("resources\\test_day1.txt");
			day->LoadFile(inputfilename);
			day->Parse();

			Assert::IsTrue(day->m_leftList.size() == day->m_rightList.size());
			Assert::IsTrue(day->m_leftList == std::vector<int>{3,4,2,1,3,3});
			Assert::IsTrue(day->m_rightList == std::vector<int>{4, 3, 5, 3, 9, 3});

			delete day;
		}
	};
}
