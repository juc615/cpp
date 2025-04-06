#include <iostream>
using namespace std;

int main() {
    int width, height, numMines;

    cout << "지뢰맵의 가로 크기(최대 80): ";
    cin >> width;

    cout << "지뢰맵의 세로 크기(최대 40): ";
    cin >> height;

    cout << "매설할 지뢰의 개수: ";  // ✅ 이 줄이 꼭 있어야 해!
    cin >> numMines;

    cout << "설정 완료! " << width << "x" << height << " 맵에 지뢰 " << numMines << "개를 매설합니다.\n";

    // 이후에 지뢰 무작위로 배치하는 코드 추가

    return 0;
}
