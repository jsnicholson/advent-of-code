#include "Day5.h"

#include <iostream>
#include <unordered_map>

void Day5::Parse() {
    const std::string lineDelimiter = std::string(" -> ");
    const std::string pointDelimiter = std::string(",");
    for (std::list<std::string>::iterator it = data.begin(); it != data.end(); it++) {
        size_t indexDelimiter = it->find(lineDelimiter);
        std::string pointFirst = it->substr(0, indexDelimiter);
        std::string pointSecond = it->substr(indexDelimiter + lineDelimiter.length(), it->length());
        listLine.push_back(std::make_pair(StringToPoint(pointFirst),StringToPoint(pointSecond)));
    }
}

int Day5::Part1() {
    std::unordered_map<std::string, int> mapPointsSeen;
    int result = 0;
    for (Line l : listLine) {
        Point pointFirst = l.first;
        Point pointSecond = l.second;
        // x is same vertical
        if (l.first.x == l.second.x) {
            if (pointFirst.y > pointSecond.y) std::swap(pointFirst, pointSecond);
            while (pointFirst.y <= pointSecond.y) {
                auto it = mapPointsSeen.find(PointToString(pointFirst));
                if (it == mapPointsSeen.end())
                    mapPointsSeen.insert({ PointToString(pointFirst),1 });
                else
                    it->second++;

                pointFirst.y++;
            }
        }
        // y is same horizontal
        else if (l.first.y == l.second.y) {
            if (pointFirst.x > pointSecond.x) std::swap(pointFirst, pointSecond);
            while (pointFirst.x <= pointSecond.x) {
                auto it = mapPointsSeen.find(PointToString(pointFirst));
                if (it == mapPointsSeen.end())
                    mapPointsSeen.insert({ PointToString(pointFirst),1 });
                else
                    it->second++;

                pointFirst.x++;
            }
        }
    }
    // count how many times we overlapped
    for (auto p : mapPointsSeen) {
        if (p.second > 1)
            result++;
    }
    return result;
}

int Day5::Part2() {
    std::unordered_map<std::string, int> mapPointsSeen;
    int result = 0;
    for (Line l : listLine) {
        Point pointFirst = l.first;
        Point pointSecond = l.second;
        // x is same vertical
        if (l.first.x == l.second.x) {
            if (pointFirst.y > pointSecond.y) std::swap(pointFirst, pointSecond);
            while (pointFirst.y <= pointSecond.y) {
                auto it = mapPointsSeen.find(PointToString(pointFirst));
                if (it == mapPointsSeen.end())
                    mapPointsSeen.insert({ PointToString(pointFirst),1 });
                else
                    it->second++;

                pointFirst.y++;
            }
        }
        // y is same horizontal
        else if (l.first.y == l.second.y) {
            if (pointFirst.x > pointSecond.x) std::swap(pointFirst, pointSecond);
            while (pointFirst.x <= pointSecond.x) {
                auto it = mapPointsSeen.find(PointToString(pointFirst));
                if (it == mapPointsSeen.end())
                    mapPointsSeen.insert({ PointToString(pointFirst),1 });
                else
                    it->second++;

                pointFirst.x++;
            }
        }
        // line is diagonal (only 45 degs)
        else {
            if (pointFirst.x > pointSecond.x) std::swap(pointFirst, pointSecond);
            while (pointFirst.x <= pointSecond.x) {
                auto it = mapPointsSeen.find(PointToString(pointFirst));
                if (it == mapPointsSeen.end())
                    mapPointsSeen.insert({ PointToString(pointFirst),1 });
                else
                    it->second++;

                pointFirst.x++;
                // positive diagonal
                if (pointFirst.y < pointSecond.y)
                    pointFirst.y++;
                // negative diagonal
                else if (pointFirst.y > pointSecond.y)
                    pointFirst.y--;

            }
        }
    }
    // count how many times we overlapped
    for (auto p : mapPointsSeen) {
        if (p.second > 1)
            result++;
    }
    return result;
}

Day5::Point Day5::StringToPoint(std::string str) {
    const std::string delimiter = std::string(",");
    const size_t index = str.find(delimiter);
    std::string x = str.substr(0, index);
    std::string y = str.substr(index + 1, str.length());
    return Point(std::stoi(x), std::stoi(y));
}

std::string Day5::PointToString(Day5::Point p) {
    std::string s = std::to_string(p.x) + ',' + std::to_string(p.y);
    return s;
}

std::ostream& operator<<(std::ostream& os, const Day5::Point& p)
{
    return os << p.x << ',' << p.y;
}

std::ostream& operator<<(std::ostream& os, const Day5::Line& l)
{
    return os << l.first << " -> " << l.second;
}
