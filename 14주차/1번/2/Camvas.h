#pragma once
#include <iostream>
#include <string>
#include <vector>

class Canvas {
public:
    Canvas(int width, int height);
    void clear();
    void draw(int x, int y, char brush);
    void print() const;
    int get_width() const;
    int get_height() const;

private:
    int width_;
    int height_;
    std::vector<std::string> grid_;
};
