#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>

class RankingBoard {
private:
    std::vector<std::pair<std::string, int>> rankings_;
public:
    void addScore(const std::string& name, int score) {
        rankings_.emplace_back(name, score);
        std::sort(rankings_.begin(), rankings_.end(),
                  [](auto& a, auto& b) { return a.second > b.second; });
    }

    void print() const {
        std::cout << "[랭킹 목록]\n";
        for (const auto& entry : rankings_) {
            std::cout << entry.first << " : " << entry.second << "\n";
        }
    }

    void saveToFile(const std::string& filename) const {
        std::ofstream ofs(filename);
        if (!ofs) {
            std::cerr << "파일 저장 실패: " << filename << std::endl;
            return;
        }
        for (const auto& entry : rankings_) {
            ofs << entry.first << "," << entry.second << "\n";
        }
        std::cout << "랭킹이 저장되었습니다: " << filename << std::endl;
    }
};
