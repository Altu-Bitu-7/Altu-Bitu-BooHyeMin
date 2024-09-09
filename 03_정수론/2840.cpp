#include <iostream>
#include <vector>

using namespace std;

string findAlpha(int n, int k) {

    vector<char> alphas(n, '?'); // n 만큼의 크기의 벡터를 '?'로 초기화

    int idx = 0;
    bool flag = true;

    for (int i = 0; i < k; i++) {
        int num;
        char alpha;

        cin >> num >> alpha;

        int order = (idx + num) % n; // 화살표가 가리키는 곳

        if (alphas[order] == '?') { // 화살표가 가리키는 곳이 물음표일 때
            for (int j = 0; j < n; j++) {
                if (alphas[j] == alpha) { // 넣을 알파벳이 중복인지 검사
                    flag = false;
                    break;
                }
            }
            alphas[order] = alpha; // 중복이 아닐 경우 해당 위치에 저장
        
        } else if (alphas[order] != alpha) {
            flag = false; // 알파벳을 넣어야 할 곳에 다른 알파벳이 있다면 false
        }

        idx = order;

    }
    
    string output = "";

    if (flag == false) {
        output = "!";
    } else {
        for (int j = 0; j < n; j++) {
        if (idx < 0) {
            idx += n;
        }
        output += alphas[idx];
        idx--;
    }

    }

    return output;
    
}

int main() {
    // 입력
    int n, k;
    cin >> n >> k;

    cout << findAlpha(n, k);

    return 0;
}
