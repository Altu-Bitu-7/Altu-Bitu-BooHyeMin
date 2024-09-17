#include <iostream>
#include <vector>

using namespace std;

void count(string word, vector<int>& v) { // 단어에 존재하는 알파벳의 위치에 해당하는 숫자를 증가시킴으로써 특정 알파벳 개수 카운트
    for (int i = 0; i < word.size(); i++) {
        v[word[i] - 'A'] += 1;
    }
}

bool cmp(vector<int>& v1, vector<int>& v2) {
    int cnt = 0;
    for (int i = 0; i < 26; i++) {
        cnt += abs(v1[i] - v2[i]); // 알파벳 개수의 차이를 모두 더함
    }
    
    if (cnt > 2) { // 차이가 2보다 큰 경우 비슷한 단어가 아님
        return false;
    }

    return true;
}


int main() {
    int n;
    cin >> n;

    vector<int> v1(26, 0);

    string input, test;
    cin >> input;

    count(input, v1);

    int cnt = 0;
    for (int i = 1; i < n; i++) {
        cin >> test;
        int is = input.size();
        int ts = test.size();

        if ((abs(is - ts)) > 1) { // 단어의 길이의 차가 1보다 클 경우 비슷한 단어 아님
            continue;
        }

        vector<int> v2(26, 0);
        count(test, v2);

        if (cmp(v1, v2)) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}