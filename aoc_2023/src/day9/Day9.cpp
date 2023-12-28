#include "Day9.h"

#include "Utils.hpp"

void Day9::Parse() {
    for (std::vector<std::string>::const_iterator it = data.begin(); it != data.end(); it++) {
        std::string line = *it;
        auto measurementTokens = Utils::Split(line, ' ');
        std::vector<int> measurements;
        std::transform(measurementTokens.begin(), measurementTokens.end(), std::back_inserter(measurements),
            [](const std::string& str) {
                return std::stoi(str);
            });
        m_measurements.push_back(measurements);
    }
}

std::string Day9::Part1() {
    long total = 0;

    for (const auto& measurements : m_measurements) {
        total += PredictNextValue(measurements);
    }

    return std::to_string(total);
}

std::string Day9::Part2() {
    long total = 0;

    for (const auto& measurements : m_measurements) {
        if (measurements.front() == 10) {
            auto f = 3;
        }
        total += PredictPreviousValue(measurements);
    }

    return std::to_string(total);
}

int Day9::PredictNextValue(const std::vector<int> values) {
    if (std::all_of(values.begin(), values.end(), [](int i) { return i == 0; }))
        return 0;

    std::vector<int> differences = CalculateDifferences(values);

    return values.back() + PredictNextValue(differences);
}

int Day9::PredictPreviousValue(const std::vector<int> values) {
    if (std::all_of(values.begin(), values.end(), [](int i) { return i == 0; }))
        return 0;

    std::vector<int> differences = CalculateDifferences(values);

    return values.front() - PredictPreviousValue(differences);
}

std::vector<int> Day9::CalculateDifferences(const std::vector<int> v) {
    std::vector<int> differences;
    for (size_t i = 0; i < v.size() - 1; i++)
        differences.push_back(v[i + 1] - v[i]);
    return differences;
}