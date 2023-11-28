#pragma once
#include "Day.h"

#include <functional>
#include <map>

typedef uint64_t item;

class Monkey {
public:
	// plainTextDescription needs to be parsed to fill out members
	Monkey(std::string plainTextDescription);

private:
	std::vector<item> m_items;
	std::function<void(item&)> m_operation;
	int m_testDivisibleBy;
	size_t m_ifTestTrueThrowToMonkeyNumber, m_ifTestFalseThrowToMonkeyNumber;
	int m_itemsInspected;

private:
	const std::string m_tokenStartingItems = "Starting items: ";
	const std::string m_tokenOperation = "Operation: ";
	const std::string m_tokenTestDivisbleBy = "Test: ";
	const std::string m_tokenTrue = "If true: ";
	const std::string m_tokenFalse = "If false: ";

	const enum TermType {
		constant = 1,
		variable = 2
	};

	const std::map<std::string, std::function<void(std::string)>> m_mapTokensToProcess = {
		{ m_tokenStartingItems, [=](std::string string) {this->ProcessStartingItems(string); } },
		{ m_tokenOperation, [=](std::string string) {this->ProcessOperation(string); } },
		{ m_tokenTestDivisbleBy, [=](std::string string) {this->ProcessTest(string); } },
		{ m_tokenTrue, [=](std::string string) {this->ProcessTestTrue(string); } },
		{ m_tokenFalse, [=](std::string string) {this->ProcessTestFalse(string); } }
	};

private:
	void ProcessStartingItems(const std::string);
	void ProcessOperation(const std::string);
	void ProcessTest(const std::string);
	void ProcessTestTrue(const std::string);
	void ProcessTestFalse(const std::string);

	void InspectFirstItem();
	size_t DecideWhereToThrowItem();

public:
	void InspectAllItems();
	
	void ThrowItem(const size_t monkeyToThrowTo);
	void CatchItem(const item itemCaught);
	int GetItemsInspectedCount() { return m_itemsInspected; }
	void ShowItems();
};

class Day11 : public Day {
public:
	std::vector<Monkey*> m_monkeys;

private:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;

	bool DoesStringStartWithToken(const std::string string, const std::string token);
	void CatchItems();
};