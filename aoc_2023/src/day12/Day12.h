#pragma once
#include "Day.h"

#include <string>
#include <unordered_map>

class Day12 : public Day {
public:
	typedef std::pair<size_t, size_t> coordinate;
	typedef size_t nodename;
	typedef std::vector<nodename> edges;

	std::unordered_map<nodename, edges> m_graph;
	coordinate m_gridSize;
	size_t m_gridSizeFlat;
	nodename m_start = INT_MIN, m_end = INT_MIN;

private:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;

public:
	void FindAndReplaceStartAndEnd();
	std::vector<nodename> GetNeighbours(coordinate);
	bool IsCoordinateInGrid(coordinate coord, coordinate gridSize);
	bool IsValidNeighbour(int value, int neighbourValue);
	size_t FlattenCoordinate(coordinate coord);
	coordinate FlatIndexToCoordinate(size_t flatIndex);
	int FewestSteps(nodename start, nodename end);
	std::vector<nodename> FindPointsOfLowestElevation();
	char GetValue(coordinate coord);
	char GetValueWithFlatIndex(size_t flatIndex);
};