#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    // 입력
    string input;
    cin >> input;

    vector<int> alpha_cnt (26, 0);
    vector<char> alphas = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    // 각 알파벳의 개수를 저장함
    for (int i = 0; i < input.length(); i++) {
        alpha_cnt[input[i] - 'A']++;
    }

    string ans = "";
    char middle;

    int odd = 0, flag = 0;
    for (int i = 0; i < alpha_cnt.size(); i++) {
        if (alpha_cnt[i] % 2 != 0) { // 알파벳 개수가 홀수일 때
            odd++;

            if (odd > 1) { // 홀수개인 알파벳이 2개 이상이면 팰린드롬 생성 불가능
                flag = 1;
                break;
            }

            flag = 2;
            middle = alphas[i]; // 중앙에 홀수개 알파벳 1개를 무조건 삽입해야 하기 때문에 따로 저장
        }
        
        for (int j = 0; j < alpha_cnt[i]/2; j++) { // 알파벳 개수를 절반씩 이어붙임
            ans += alphas[i];
        }
    }

    if (flag == 1) {
        cout << "I'm Sorry Hansoo";
    } else {
        cout << ans; // 절반씩 이어붙인 문장 먼저 출력
        if (flag == 2) { // 홀수개 알파벳이 하나일 때 중앙에 하나 삽입
            cout << middle;
        }
        for (int i = ans.length() - 1; i >= 0; i--) { // 문장을 거꾸로 출력
            cout << ans[i];
        }
    }

    return 0;
}