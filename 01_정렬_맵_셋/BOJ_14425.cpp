#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    string input;
    set<string> s;

    for (int i = 0; i < n; i++) {
        cin >> input;
        s.insert(input);
    }

    int cnt = 0;
    for (int j = 0; j < m; j++) {
        string s_find;
        cin >> s_find;
        if (s.find(s_find) != s.end()) {
            cnt += 1;
        }
    }

    cout << cnt;

    return 0;
}
