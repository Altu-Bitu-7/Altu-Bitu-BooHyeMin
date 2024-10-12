#include <iostream>

using namespace std;

int graph[101][101] = {0, };
bool visited[101] = {false, };
int n, m;
int s1, s2;
int cnt = 0;

void dfs(int from, int num) {
    visited[from] = true;

    if (from == s2) {
        cnt = num;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (graph[from][i] == 1 && !visited[i]) {
            dfs(i, num+1);
        }
    }
}

int main() {
    cin >> n >> s1 >> s2 >> m;

    for (int i = 0; i < m; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        graph[tmp1][tmp2] = graph[tmp2][tmp1] = 1; // 단방향
    }
    
    dfs(s1, cnt);

    if (cnt == 0) { // 친척 관계가 없을 때
        cnt = -1;
    }

    cout << cnt;
    
    return 0;
}
