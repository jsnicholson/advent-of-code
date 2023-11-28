#pragma once
#include <string>
#include <vector>

class Day {

public:
	bool LoadFile(const std::string inputfilename);
	void Run(std::string inputfilename);

private:
	virtual void Parse() {};
	virtual std::string Part1();
	virtual std::string Part2();

public:
	virtual std::string GetInput() { return ""; }

protected:
	std::vector<std::string> data;
};