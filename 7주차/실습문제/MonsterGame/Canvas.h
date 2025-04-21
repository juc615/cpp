#pragma once
#include <iostream>
#include <string>
#define MAXLINES 100
using namespace std;

class Canvas {
    string line[MAXLINES];  // 화면 각 줄을 저장하는 문자열 배열
    int xMax, yMax;         // 캔버스의 너비(x)와 높이(y)

public:
    Canvas(int nx = 10, int ny = 10) : xMax(nx), yMax(ny) {
        for (int y = 0; y < yMax; y++)
            line[y] = string(xMax * 2, ' ');
    }

    void draw(int x, int y, string val) {
        if (x >= 0 && y >= 0 && x < xMax && y < yMax)
            line[y].replace(x * 2, 2, val);
    }

    void clear(string val = ". ") {  // 기본값은 점 + 공백으로 지움
        for (int y = 0; y < yMax; y++)
            for (int x = 0; x < xMax; x++)
                draw(x, y, val);
    }

    void print(const char* title = "<My Canvas>") {
        system("cls");  // 콘솔 화면 지우기 (Windows 전용)
        cout << title << endl;
        for (int y = 0; y < yMax; y++)
            cout << line[y] << endl;
        cout << endl;
    }
};
