#include <iostream>

using namespace std;

int main() {
    // 입력
    int n;
    cin >> n;  

    int cnt_1 = 0, cnt_2 = 0;
    while(n--) {
        int x;
        cin >> x;
        cnt_2 += x / 2; 
        cnt_1 += x % 2; // 2만큼 성장 가능한 횟수와 1만큼 성장 가능한 횟수 구함
    }

    if (cnt_1 == cnt_2) { // 2와 1의 개수가 같으면 모두 성장 가능함
        cout << "YES\n";
    } else if (cnt_2 > cnt_1) { // 2의 개수가 1의 개수보다 크면 2의 개수에서 1의 개수를 뺀 값이 3으로 나눠질 때 가능
        cnt_2 -= cnt_1;
        if (cnt_2 % 3 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    else { // 1의 개수가 크면 성장 불가능
        cout << "NO\n";
    }
    
    return 0;
}