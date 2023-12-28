#pragma once
#include "Day.h"

#include <map>

class Day10 : public Day {
public:
	typedef std::pair<int, int> coord;

	static inline const coord up = { 0, 1 };
	static inline const coord right = { 1, 0 };
	static inline const coord down = { 0, -1 };
	static inline const coord left = { -1, 0 };

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
	static inline const std::vector<std::pair<char, std::vector<bool>>> validPipesPerPipe = {
		{'|', {true,false,true,false}},
		{'-', {false,true,false,true}},
		{'L', {true,true,false,false}},
		{'J', {true,false,false,true}},
		{'7', {false,false,true,true}},
		{'F', {false,true,true,false}},
		{'S', {true,true,true,true}}
	};

	/*
	* holds valid pipes for each vector
	* formatted in
	* {up},
	* {right},
	* {down},
	* {left}
	* 
	* can convert using map mapVectorToIndex
	*/
	static inline const std::vector<std::vector<char>> validPipesPerVector = {
		{'|','L','J','S'},
		{'-','L','F','S'},
		{'|','7','F','S'},
		{'-','J','7','S'}
	};

private:
	void Parse() override;
	std::string Part1() override;
	std::string Part2() override;

public:
	coord m_startCoord;
	std::vector<std::string> m_grid;
};