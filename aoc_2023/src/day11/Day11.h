#pragma once
#include "Day.h"

class Day11 : public Day {
public:
	typedef std::vector<std::string> universe;
	typedef std::pair<int, int> coord;

private:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;

public:
	int CalculateShortestDiscreteDistanceBetweenPoints(const coord& a, const coord& b);
	universe CalculateExpandedUniverse(const universe& originalUniverse);
	void AddRowsToUniverse(universe& universe, std::vector<size_t> rows);
	void AddColumnsToUniverse(universe& universe, std::vector<size_t> columns);
	std::vector<size_t> GetIndicesOfEmptyRows(const universe& universe);
	std::vector<size_t> GetIndicesOfEmptyColumns(const universe& universe);
	std::vector<coord> FindAllGalaxies(const universe& universe);

public:
	universe m_universe;
};