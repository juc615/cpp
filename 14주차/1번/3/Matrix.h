#pragma once
#include <iostream>
#include <iomanip>
#include <vector>

template <typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data_;
    int rows_, cols_;
public:
    Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
        data_.resize(rows, std::vector<T>(cols));
    }
    T& at(int row, int col) {
        return data_.at(row).at(col);
    }
    const T& at(int row, int col) const {
        return data_.at(row).at(col);
    }
    int rows() const { return rows_; }
    int cols() const { return cols_; }

    void print() const {
        for (const auto& row : data_) {
            for (const auto& val : row) {
                std::cout << std::setw(3) << val;
            }
            std::cout << std::endl;
        }
    }
};
