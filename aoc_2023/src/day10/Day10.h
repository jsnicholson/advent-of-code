#pragma once
#include "Day.h"

#include <map>

class Day10 : public Day {
public:
	typedef std::pair<int, int> coord;
	typedef std::pair<int, int> direction;

	static inline const direction up = { 0, -1 };
	static inline const direction right = { 1, 0 };
	static inline const direction down = { 0, 1 };
	static inline const direction left = { -1, 0 };
	static inline const direction none = { 0, 0 };

	static inline const std::map<direction, int> mapVectorToIndex = {
		{up,0},{right,1},{down,2},{left,3}
	};
	
	/*
	* map of valid pipes for each pipe
	* formatted in 
	* {pipe, {
	*	{up},{right},{down},{left}
	* }}
	* 
	* can convert using map mapVectorToIndex
	*/
	static inline const std::map<char, std::vector<direction>> mapPipeToDirections = {
		{'|', {up, down}},
		{'-', {right, left}},
		{'L', {up, right}},
		{'J', {up, left}},
		{'7', {down,left}},
		{'F', {right, down}},
		{'S', {up,right,down,left}}
	};

	/*
	* if we look in direction, what pipes are valid?
	*/
	static inline const std::map<direction,std::vector<char>> mapDirectionToPipes = {
		{up, {'|','7','F','S'}},
		{right, {'-','J','7','S'}},
		{down, {'|','L','J','S'}},
		{left, {'-','L','F','S'}},
	};

private:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;

public:
	std::vector<coord> CalculateLoop(const coord& startCoord);
	std::vector<direction> GetValidDirections(const coord& fromCoord, const direction& lastDirection);
	std::pair<char, coord> FindConnectingNeighbour(const coord&,const std::vector<direction>&);
	int ShoeLace(const std::vector<coord>& path);

public:
	coord m_startCoord;
	std::vector<std::string> m_grid;
};