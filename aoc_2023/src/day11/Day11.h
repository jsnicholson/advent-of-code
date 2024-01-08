#pragma once
#include "Day.h"

class Day11 : public Day {
public:
	typedef std::vector<std::string> universe;
	typedef std::pair<int64_t, int64_t> coord;

private:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;

public:
	int CalculateShortestDiscreteDistanceBetweenPoints(const coord& a, const coord& b);
	universe CalculateExpandedUniverse(const universe& originalUniverse, const int expansion);
	void AddRowsToUniverse(universe& universe, std::vector<size_t> rows, const int expansion);
	void AddColumnsToUniverse(universe& universe, std::vector<size_t> columns, const int expansion);
	std::vector<size_t> GetIndicesOfEmptyRows(const universe& universe);
	std::vector<size_t> GetIndicesOfEmptyColumns(const universe& universe);
	std::vector<coord> FindAllGalaxies(const universe& universe);
	coord CalculateDisplacementAfterExpansion(const std::vector<size_t>& vecEmptyRows, const std::vector<size_t>& vecEmptyColumns, const coord& point);

public:
	universe m_universe;
	const int m_expansionPart1 = 2;
	const int m_expansionPart2 = 1000000;
};