#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

class RankingBoard {
private:
    std::vector<std::pair<std::string, int>> rankings_;
public:
    void addScore(const std::string& name, int score);
    void print() const;
};
