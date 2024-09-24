#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // 입력
    int n;
    cin >> n;

    vector<int> v (n, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    long long max = 0; // 주어진 수가 크기 때문에 계산하다보면 int범위를 벗어날 가능성 존재
    for (int i = v.size() - 1; i >= 0; i--) { // 속도를 거꾸로 확인해서 큰 속도값을 확인
        if (v[i] >= max) {
            max = v[i];
        }
        else {
            if (max % v[i] == 0) {
                continue;
            }
            max = v[i] * (max / v[i] + 1); // 저장해놓은 max 값보다 큰 배수값을 구함
        }
    }

    cout << max;

    return 0;
}