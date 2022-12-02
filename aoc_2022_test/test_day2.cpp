#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include "Days.hpp"
#include "Utils.hpp"

namespace aoc2022test
{

	TEST_CLASS(TestDay2)
	{
		std::string testfilename = _PROJECTDIR + std::string("resources\\test_day2.txt");
	public:
		TEST_METHOD(TestDay2Parse) {
			// setup
			Day2* day = new Day2();
			day->LoadFile(testfilename);
			day->Parse();

			auto roundFirst = day->m_rounds.front();
			auto roundLast = day->m_rounds.back();

			// assert
			Assert::IsTrue(roundFirst == std::make_pair('A','X'));
			Assert::IsTrue(roundLast == std::make_pair('C', 'X'));

			// cleanup 
			delete day;
		}

		TEST_METHOD(TestDay2ScoreCalculatedCorrectlyForLoss) {
			// setup
			Day2* day = new Day2();
			day->Run(testfilename);

			auto playedRockAndLost = day->CalculateRoundScore(std::make_pair('P', 'R'));
			auto playedPaperAndLost = day->CalculateRoundScore(std::make_pair('S', 'P'));
			auto playerScissorsAndLost = day->CalculateRoundScore(std::make_pair('R','S'));

			// assert
			Assert::AreEqual(1, playedRockAndLost);
			Assert::AreEqual(2, playedPaperAndLost);
			Assert::AreEqual(3, playerScissorsAndLost);

			// cleanup
			delete day;
		}

		TEST_METHOD(TestDay2ScoreCalculatedCorrectlyForDraw) {
			// setup
			Day2* day = new Day2();
			day->Run(testfilename);

			auto playedRockAndDrew = day->CalculateRoundScore(std::make_pair('R', 'R'));
			auto playedPaperAndDrew = day->CalculateRoundScore(std::make_pair('P', 'P'));
			auto playerScissorsAndDrew = day->CalculateRoundScore(std::make_pair('S', 'S'));

			// assert
			Assert::AreEqual(4, playedRockAndDrew);
			Assert::AreEqual(5, playedPaperAndDrew);
			Assert::AreEqual(6, playerScissorsAndDrew);

			// cleanup
			delete day;
		}

		TEST_METHOD(TestDay2ScoreCalculatedCorrectlyForWin) {
			// setup
			Day2* day = new Day2();
			day->Run(testfilename);

			auto playedRockAndWon = day->CalculateRoundScore(std::make_pair('S', 'R'));
			auto playedPaperAndWon = day->CalculateRoundScore(std::make_pair('R', 'P'));
			auto playerScissorsAndWon = day->CalculateRoundScore(std::make_pair('P', 'S'));

			// assert
			Assert::AreEqual(7, playedRockAndWon);
			Assert::AreEqual(8, playedPaperAndWon);
			Assert::AreEqual(9, playerScissorsAndWon);

			// cleanup
			delete day;
		}
	};
}
