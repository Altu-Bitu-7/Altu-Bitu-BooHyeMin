#include <iostream>

using namespace std;

int dp[301]; // 최대 점수
int a[301];

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> a[i];
	
    dp[0] = 0;
    dp[1] = a[1];
	dp[2] = a[1] + a[2];

	for (int i = 3; i <= n; ++i) { // 3번째부터 n번째까지 최대 점수 계산
		dp[i] = max(dp[i - 3] + a[i - 1] + a[i], dp[i - 2] + a[i]);
        // i-3 -> i-1 -> i 와 i-2 -> i 비교
    }

	cout << dp[n];

    return 0;
}
