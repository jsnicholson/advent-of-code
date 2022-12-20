#pragma once
#include "Day.h"

#include <string>
#include <unordered_map>

class Day12 : public Day {
public:
	typedef std::pair<size_t, size_t> coordinate;
	typedef std::string nodename;
	typedef std::vector<nodename> edges;
	std::unordered_map<nodename, edges> m_graph;

	coordinate m_gridSize, m_start, m_end;

private:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;

public:
	std::string CoordToName(coordinate);
	void CheckForStartAndEnd(coordinate coord);
	std::vector<nodename> GetNeighbours(coordinate);
	bool IsCoordinateInGrid(coordinate coord, coordinate gridSize);
	bool IsValidNeighbour(int value, int neighbourValue);
	char GetValue(coordinate coord);
};