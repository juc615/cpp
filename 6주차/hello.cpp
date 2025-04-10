#include <iostream>
#include <fstream>
#include <string>
#include <windows.h> // UTF-8 출력을 위한 헤더
using namespace std;

#define MAXWORDS 1000

struct WordPair {
    string eng;
    string kor;
};

class MyDic {
    WordPair words[MAXWORDS];
    int nWords = 0;

public:
    inline void add(string eng, string kor) {
        if (nWords < MAXWORDS) {
            words[nWords].eng = eng;
            words[nWords].kor = kor;
            nWords++;
        }
    }

    inline void load(string filename) {
        ifstream fin(filename);
        string eng, kor;
        while (fin >> eng >> kor) {
            add(eng, kor);
        }
        fin.close();
    }

    inline void store(string filename) {
        ofstream fout(filename);
        for (int i = 0; i < nWords; i++) {
            fout << words[i].eng << " " << words[i].kor << endl;
        }
        fout.close();
    }

    inline void print() {
        for (int i = 0; i < nWords; i++) {
            cout << i << ": " << words[i].eng << " - " << words[i].kor << endl;
        }
    }

    inline string getEng(int id) {
        if (id >= 0 && id < nWords) return words[id].eng;
        return "";
    }

    inline string getKor(int id) {
        if (id >= 0 && id < nWords) return words[id].kor;
        return "";
    }
};

int main() {
    // Windows 콘솔 UTF-8 설정 (한글 깨짐 방지)
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    MyDic dic;
    dic.add("apple", "사과");
    dic.add("banana", "바나나");
    dic.add("peach", "복숭아");
    dic.print(); // 단어장 출력
    return 0;
}
