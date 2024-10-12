#include <iostream>

using namespace std;

int go[19][19] = {0, }; // 바둑판
int dx[4] = {-1, 0, 1, 1};
int dy[4] = {1, 1, 1, 0};

const int SIZE = 19;

bool isValid(int x, int y, int color) { // 확인하는 돌이 유효한지 검사
    return (x >= 0 && x < SIZE && y >= 0 && y < SIZE && go[x][y] == color); // 판 안에 있어야 하고, 확인하는 색이랑 동일한지 검사
}

bool checkWin(int x, int y) {
    int color = go[x][y];

    for (int i = 0; i < 4; i++) {
        int cnt = 1; // 현재 위치에 있는 돌

        int prev_x = x - dx[i], prev_y = y - dy[i];
        int next_x = x + dx[i], next_y = y + dy[i];
        
        if (isValid(prev_x, prev_y, color)) { // 이전 돌 검사
            continue;
        }

        while (isValid(next_x, next_y, color) && cnt < 6) { // 이후 돌 검사
            cnt++;
            next_x += dx[i];
            next_y += dy[i];            
        }

        if (cnt == 5) { // 카운트가 5일때만 true
            return true;
        }
    }
    return false;
}


int main() {
    ios::sync_with_stdio(false); // 빠른 입출력
    cin.tie(NULL);

    // 입력
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cin >> go[i][j];
        }
    }

    // 연산 & 출력
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            if (go[x][y] != 0) {
                if (checkWin(x, y)) {
                    cout << go[x][y] << "\n"; // 이긴 색 출력
                    cout << x + 1 << " " << y + 1 << "\n"; // 위치 출력

                    return 0;
                }
            }
        }
    }

    cout << "0\n"; // 이긴 돌이 없을 때 출력

    return 0;
}
