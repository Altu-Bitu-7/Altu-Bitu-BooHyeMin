#include <iostream>
#include <vector>

using namespace std;

void rotate (vector<string>& v, vector<int>& v_dir) { // 회전한 톱니바퀴 저장
    for (int i = 1; i < v.size(); i++) {
        if (v_dir[i] == 1) { // 저장한 방향이 1, 즉, 시계방향일 때
            v[i] = v[i].substr(7, 1) + v[i].substr(0, 7);
        }
        else if (v_dir[i] == -1) { // 저장한 방향이 -1, 즉, 반시계방향일 때
            v[i] = v[i].substr(1, 7) + v[i].substr(0, 1);
        }
    }
}

void getDir (vector<string>& v, vector<int>& v_dir, int num, int dir) {
    int left = num, right = num, tmp = dir;
    v_dir[num] = dir;

    while (left > 1) { // 회전 시작하는 톱니바퀴의 왼쪽을 확인
        if (v[left-1][2] == v[left][6]) { // 극이 같으면 왼쪽에서 회전하는 톱니바퀴 없음
            break;
        } else { // 극이 다르면 회전
            v_dir[left-1] = -dir; // 반대 방향으로 회전하므로 마이너스 붙임
            left--;
            dir = -dir;
        }
    }

    while (right < v.size() - 1) { // 회전 시작하는 톱니바퀴의 오른쪽 확인
        if (v[right+1][6] == v[right][2]) { // 극이 같으면 오른쪽에서 회전하는 톱니바퀴 없음
            break;
        } else { // 극이 다르면 회전
            v_dir[right+1] = -tmp; // 반대 방향으로 회전하므로 마이너스 붙임
            right++;
            tmp = -tmp;
        }
    }
}

int main() {
    // 입력
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, k;
    cin >> t;

    vector<string> v (t+1, "");

    for (int i = 1; i <= t; i++) {
        cin >> v[i];
    }

    cin >> k;
    int num, dir;

    while (k--) {
        cin >> num >> dir;
        vector<int> v_dir (t+1, 0); // 회전 방향을 저장하는 벡터를 초기화
        getDir(v, v_dir, num, dir);
        rotate(v, v_dir);
    }
    

    int cnt = 0;
    for (int i = 1; i <= t; i++) {
        if (v[i][0] == '1') { // 각 톱니바퀴의 첫 문자가 '1'일 때 cnt 증가
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}