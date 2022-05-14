#pragma once
#include "Day.h"
#include <string>
#include <map>
#include <iostream>

class Day5 : public Day {

public:
	//std::string GetInput() override { return "resources\\input_day5_prac.txt"; };

private:
	void Parse() override;
	int Part1() override;
	int Part2() override;

public:
	struct Point { 
		int x, y;
		Point(int _x, int _y) : x(_x), y(_y) {};
	};
	typedef std::pair<Point, Point> Line;

	friend std::ostream& operator<< (std::ostream& os, const Point& p);
	friend std::ostream& operator<< (std::ostream& os, const Line& l);

private:
	Point StringToPoint(std::string str);
	std::string PointToString(Point p);

private:
	std::list<Line> listLine;
};