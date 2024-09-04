#include <iostream>
#include <stack>

using namespace std;

int main() {
    // 입력
    string a, b; // 메모리 제한으로 string으로 입력 받음
    cin >> a >> b;

    // 스택
    stack<int> s1;
    stack<int> s2;
    stack<int> s3;

    for (int i = 0; i < a.size(); i++) { // string형인 첫 번째 정수를 int로 바꾸어 s1 스택에 순서대로 저장
        s1.push(a[i] - '0');
    }

    for (int j = 0; j < b.size(); j++) { // string형인 두 번째 정수를 int로 바꾸어 s2 스택에 순서대로 저장
        s2.push(b[j] - '0');
    }

    int sumNum, c = 0;

    while (!s1.empty() || !s2.empty()) {
        sumNum = 0;
        if (!s1.empty()) {
            sumNum += s1.top();
            s1.pop();
        }

        if (!s2.empty()) {
            sumNum += s2.top();
            s2.pop();
        }

        sumNum += c;

        if (sumNum >= 10) {
            c = 1;
            sumNum -= 10;
        } else {
            c = 0;
        }

        s3.push(sumNum);
    }

    if (c == 1) {
        s3.push(1);
    }

    while (!s3.empty()) {
        cout << s3.top();
        s3.pop();
    }

    return 0;
}
