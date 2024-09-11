#include <iostream>

using namespace std;
const string NUM = "666";

int getTitle(int n) {
    int cnt = 0;
    int num = 666;

    while (true) {
        string s_num = to_string(num);
        int len = s_num.length();
        if (s_num.find(NUM) < len) {
            if (++cnt == n) {
                return num;
            }
        }
        num++;
    }
    
}

int main() {
    // 입력
    int n;
    cin >> n;

    // 연산
    // 출력
    cout << getTitle(n);

    return 0;
}