#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, x;
    cin >> n;

    priority_queue<int> pq; // 우선순위큐 사용

    int a;
    while(n--) {
        cin >> x;
        if (x == 0) {
            if (pq.size() > 0) {
                cout << pq.top() << "\n";
                pq.pop();
            }
            else {
                cout << "-1\n";
            }
        }
        else {
            while(x--) {
                cin >> a;
                pq.push(a);
            }
        }
    }

    return 0;
}