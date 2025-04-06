#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ROWS = 9;
const int COLS = 9;
const int MINES = 10;

struct Cell {
    bool isMine = false;
    bool isRevealed = false;
    int adjacentMines = 0;
};

vector<vector<Cell>> board(ROWS, vector<Cell>(COLS));

void placeMines() {
    int placed = 0;
    while (placed < MINES) {
        int r = rand() % ROWS;
        int c = rand() % COLS;
        if (!board[r][c].isMine) {
            board[r][c].isMine = true;
            placed++;
        }
    }
}

void calculateAdjacents() {
    int dr[] = {-1,-1,-1,0,0,1,1,1};
    int dc[] = {-1,0,1,-1,1,-1,0,1};
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (board[r][c].isMine) continue;
            int count = 0;
            for (int i = 0; i < 8; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && board[nr][nc].isMine)
                    count++;
            }
            board[r][c].adjacentMines = count;
        }
    }
}

void printBoard(bool revealAll = false) {
    cout << "   ";
    for (int c = 0; c < COLS; c++) cout << c << " ";
    cout << "\n";
    for (int r = 0; r < ROWS; r++) {
        cout << r << " |";
        for (int c = 0; c < COLS; c++) {
            if (revealAll || board[r][c].isRevealed) {
                if (board[r][c].isMine) cout << "* ";
                else cout << board[r][c].adjacentMines << " ";
            } else {
                cout << "# ";
            }
        }
        cout << "\n";
    }
}

bool reveal(int r, int c) {
    if (r < 0 || r >= ROWS || c < 0 || c >= COLS || board[r][c].isRevealed) return true;
    board[r][c].isRevealed = true;
    if (board[r][c].isMine) return false;
    if (board[r][c].adjacentMines == 0) {
        // Auto-reveal 주변 셀
        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {
                if (dr != 0 || dc != 0)
                    reveal(r + dr, c + dc);
            }
        }
    }
    return true;
}

bool isWin() {
    int revealedCount = 0;
    for (int r = 0; r < ROWS; r++)
        for (int c = 0; c < COLS; c++)
            if (board[r][c].isRevealed)
                revealedCount++;
    return revealedCount == (ROWS * COLS - MINES);
}

int main() {
    srand(time(0));
    placeMines();
    calculateAdjacents();

    bool gameOver = false;
    while (!gameOver) {
        printBoard();
        int r, c;
        cout << "셀 선택 (행 열): ";
        cin >> r >> c;
        if (!reveal(r, c)) {
            cout << "💥 지뢰를 밟았습니다! 게임 오버!\n";
            printBoard(true);
            break;
        }
        if (isWin()) {
            cout << "🎉 모든 셀을 찾았습니다! 승리!\n";
            printBoard(true);
            break;
        }
    }
    return 0;
}
