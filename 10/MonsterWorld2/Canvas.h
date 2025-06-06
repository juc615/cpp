#pragma once
#include <iostream>
#include <string>
#define MAXLINES 100
using namespace std;

class Canvas {
	string line[MAXLINES];	// 화면 출력을 위한 문자열
	int xMax, yMax;		// 맵의 크기
public:
	Canvas(int nx = 10, int ny = 10) : xMax(nx), yMax(ny) {
		for (int y = 0; y < yMax; y++)
			line[y] = string(xMax * 2, ' ');
	}
	void draw(int x, int y, string val) {
		if (x >= 0 && y >= 0 && x<xMax && y<yMax)
			line[y].replace(x * 2, 2, val);
	}
	void clear(string val = ". ") {
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				draw(x, y, val);
	}
	void print(const char *title = "<My Canvas>") {  // 수정된 부분
		system("cls");
		cout << title << endl;
		for (int y = 0; y < yMax; y++)
			cout << line[y] << endl;
		cout << endl;
	}
};
