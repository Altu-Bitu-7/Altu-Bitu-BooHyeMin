#include <iostream>
#include <queue>

// 요세푸스 문제
using namespace std;

int main() {
    // 입력
    int n, k;
    cin >> n >> k;

    // 원형 큐
    queue<int> q;

    for (int i = 1; i <= n; i++) { // 큐에 1~n을 할당
        q.push(i);
    }

    // 출력
    cout << "<";

    while(!q.empty()) { // 큐가 비어있을 때까지 반복
        for (int i = 1; i < k; i++) { // k번째 사람을 제거하기 위해 첫 번째부터 k-1번째 사람을 제거하고 큐의 맨 뒤에 넣음
            int x = q.front(); // 큐의 첫 요소를 x에 저장
            q.pop(); // 첫 요소 삭제
            q.push(x); // 저장해놓은 첫 요소를 큐의 맨 뒤에 넣음
        }

        cout << q.front(); // k번째 요소 출력 후 pop으로 삭제
        q.pop();

        if (!q.empty()) {
            cout << ", " ;
        } else {
            cout << ">";
        }
    }

    return 0;
}
