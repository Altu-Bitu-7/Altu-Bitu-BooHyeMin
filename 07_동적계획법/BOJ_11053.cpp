#include <iostream>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int a[1001], dp[1001]; // dp : 각 원소까지의 가장 긴 부분수열 길이 저장

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int sum = 0; // 최대 길이
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[i] > a[j]) { // 이전 원소와 비교 (a[i]가 a[j]보다 크면 a[i]를 부분 수열에 포함)
                dp[i] = max(dp[i], dp[j] + 1); // dp[i] 갱신
            }
        }
        sum = max(sum, dp[i]); // 최대 길이 갱신
    }
    cout << sum;

    return 0;
}
