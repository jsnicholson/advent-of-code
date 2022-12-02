#pragma once
#include <list>
#include <string>

class Day {

public:
	bool LoadFile(const std::string inputfilename);
	void Run(std::string inputfilename);

private:
	virtual void Parse() {};
	virtual int Part1();
	virtual int Part2();

public:
	virtual std::string GetInput() { return ""; }

protected:
	std::list<std::string> data;
};