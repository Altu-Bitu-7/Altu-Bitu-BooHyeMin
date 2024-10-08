#include <iostream>

using namespace std;

int n, m;
int graph[101][101] = {0, };
bool visited[101] = {false, };
int cnt = 0;

void dfs(int from) { // dfs 활용
    for (int i = 1; i <= n; i++) {
        if (graph[from][i] == 1) { // from과 i가 연결되어 있을 때
            if (!visited[i]) {
                visited[i] = true;
                cnt++;
                dfs(i);
            }
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        graph[tmp1][tmp2] = graph[tmp2][tmp1] = 1; // 단방향
    }

    visited[1] = true; // 1번부터 바이러스가 걸리므로
    dfs(1);

    cout << cnt;

    return 0;
}
