#include <iostream>
#include <queue>

using namespace std;

struct cmp {
    bool operator() (const int& x1, const int& x2) { // 최소 힙 구현
        return x1 > x2;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, x;
    cin >> n;

    priority_queue<int, vector<int>, cmp> pq; // 우선순위큐 사용

    int tmp = n;
    while (n--) {
        for (int i = 0; i < tmp; i++) {
            cin >> x;
            pq.push(x);
            if (pq.size() > tmp) { // 큐의 크기가 n보다 커지면 현재 큐에서 가장 작은 숫자를 삭제
                pq.pop();
            }
        }
    }
    
    cout << pq.top(); // 큐의 top에 위치한 숫자가 n번째로 큰 숫자가 됨

    return 0;
}
