#include "Day3.h"
#include "Utils.hpp"

void Day3::Parse() {
	m_program = std::accumulate(data.begin(), data.end(), std::string{});
}

std::string Day3::Part1() {
	int result = 0;

	std::vector<instruction> instructions = Utils::FindAll(m_program, std::regex(R"(mul\(\d+,\d+\))"));

	for (std::vector<instruction>::const_iterator it = instructions.begin(); it != instructions.end(); it++) {
		result += Day3::ExecuteMultiply(*it);
	}

	return std::to_string(result);
}

std::string Day3::Part2() {
    return std::string("unimplemented");
}

int Day3::ExecuteMultiply(instruction instruction) {
	operands operands = Day3::ExtractOperands(instruction);
	return operands.first * operands.second;
}

Day3::operands Day3::ExtractOperands(instruction instruction) {
	auto tokens = Utils::Split(instruction, '(');
	tokens = Utils::Split(tokens[1], ',');
	int first = std::stoi(tokens[0]);
	tokens = Utils::Split(tokens[1], ')');
	int second = std::stoi(tokens[0]);
	return std::make_pair(first, second);
}
