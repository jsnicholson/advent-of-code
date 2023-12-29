#pragma once
#include "Day.h"

#include <map>

class Day10 : public Day {
public:
	typedef std::pair<int, int> coord;

	static inline const coord up = { 0, -1 };
	static inline const coord right = { 1, 0 };
	static inline const coord down = { 0, 1 };
	static inline const coord left = { -1, 0 };
	static inline const coord none = { 0, 0 };

	static inline const std::map<coord, int> mapVectorToIndex = {
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
	static inline const std::map<char, std::vector<coord>> mapPipeToDirections = {
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
	static inline const std::map<coord,std::vector<char>> mapDirectionToPipes = {
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
	std::pair<char, coord> FindConnectingNeighbour(const coord&,const std::vector<coord>&);

public:
	coord m_startCoord;
	std::vector<std::string> m_grid;
};