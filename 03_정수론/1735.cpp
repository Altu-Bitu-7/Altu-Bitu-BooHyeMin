#include <iostream>

using namespace std;

int getGcd(int a, int b) { // 재귀함수로 최대공약수를 구함
    if (b == 0) {
        return a;
    }
    return getGcd(b, a % b);
}

int main() {
    // 입력
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int num = a * d + b * c; // 분자
    int den = b * d; // 분모

    int gcd = getGcd(max(num, den), min(num, den));

    // 분자, 분모에 최대공약수를 나눠줌
    num /= gcd;
    den /= gcd;

    // 출력
    cout << num << " " << den;

    return 0;
}
