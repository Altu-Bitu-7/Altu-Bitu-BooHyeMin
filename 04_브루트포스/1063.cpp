#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

bool isValid(int c, int r) { // 킹과 돌이 체스판 밖으로 나가는지 확인
    if (c >= 65 && c <= 72 && 1 <= r && r <= 8) {
        return true;
    }
    return false;
}


void move(string cmd, int& col, int& row) { // 명령어에 따라 킹과 돌을 움직임
    if (cmd == "R") {
        ++col;
    } else if (cmd == "L") {
        --col;
    } else if (cmd == "B") {
        --row;
    } else if (cmd == "T") {
        ++row;
    } else if (cmd == "RT") {
        ++col; ++row;
    } else if (cmd == "LT") {
        --col; ++row;
    } else if (cmd == "RB") {
        ++col; --row;
    } else if (cmd == "LB") {
        --col; --row;
    }
}

void checkStone(string cmd, bool& flag, int& s_col, int& s_row) { // 돌 체크
    int c_tmp = s_col;
    int r_tmp = s_row;

    move(cmd, c_tmp, r_tmp);
    if (isValid(c_tmp, r_tmp)) {
        s_col = c_tmp; s_row = r_tmp;
    } else {
        flag = false;
    }
}

void checkKing(string cmd, int& k_col, int& k_row, int& s_col, int& s_row) {
    int kc = k_col; int kr = k_row; // 킹의 위치를 임시로 저장
    int sc = s_col; int sr = s_row; // 돌의 위치를 임시로 저장

    move(cmd, kc, kr); // 킹을 이동
    if (isValid(kc, kr)) {
        if (kc == sc && kr == sr) { // 킹과 돌이 겹쳤을 때
            bool flag = true;
            checkStone(cmd, flag, sc, sr);
            if (flag) { // 돌이 이동 가능하면 킹과 돌을 모두 이동
                k_col = kc; k_row = kr;  
                s_col = sc; s_row = sr; 
            }
        } else { // 킹과 돌이 겹치지 않으면 킹만 이동
            k_col = kc;
            k_row = kr; 
        }
    }
}

void sol(int n, string king, string stone) {
    char k_col_c, s_col_c;
    int k_row, s_row;
    
    istringstream iss(king); // 초기 킹의 위치를 문자와 숫자로 분리
    iss >> k_col_c >> k_row;
    istringstream iss2(stone); // 초기 돌의 위치를 문자와 숫자로 분리
    iss2 >> s_col_c >> s_row;

    int k_col = int(k_col_c); // 초기 킹의 열 위치(대문자)를 숫자로 변환
    int s_col = int(s_col_c); // 초기 돌의 열 위치(대문자)를 숫자로 변환

    while (n--) {
        // 명령어 입력
        string cmd;
        cin >> cmd;

        checkKing(cmd, k_col, k_row, s_col, s_row);    
    }

    // 출력
    cout << char(k_col) << k_row << "\n";
    cout << char(s_col) << s_row << "\n";

}

int main() {
    // 킹과 돌의 초기 위치 입력
    string king, stone;
    int n;

    cin >> king >> stone >> n;

    // 연산
    sol(n, king, stone);

    return 0;
}
