#include <iostream>
#include <bitset>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int m;
    cin >> m;

    bitset<21> bit; // 0 21개로 초기화

    while(m--) {
        string cmd;
        cin >> cmd;

        if (cmd == "add") {
            int x;
            cin >> x;
            if (bit[x] == 0) {
                bit[x] = 1;
            }
        } 
        
        else if (cmd == "remove") {
            int x;
            cin >> x;
            if (bit[x] == 1) {
                bit[x] = 0;
            }
        }

        else if (cmd == "check") {
            int x;
            cin >> x;
            if (bit[x] == 1) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        } 
        
        else if (cmd == "toggle") {
            int x;
            cin >> x;
            if (bit[x] == 1) {
                bit[x] = 0;
            } else {
                bit[x] = 1;
            }
        }

        else if (cmd == "all") {
            bit.set();
        }

        else if (cmd == "empty") {
            bit.reset();
        }
    }

    return 0;
}