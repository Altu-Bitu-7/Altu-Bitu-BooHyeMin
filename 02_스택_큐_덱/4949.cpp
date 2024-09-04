#include <iostream>
#include <stack>

using namespace std;

int main() {
    while (1) {
        string str;
        stack<char> s;
        int flag = 1;

        getline(cin, str); // 공백을 포함한 문자열을 받기 위함
        if (str == ".") {
            break;
        } else {
            for (int i = 0; i < str.size(); i++) {
                if (str[i] == '(' || str[i] == '[') s.push(str[i]); // 여는 괄호이면 push
                else if (str[i] == ')') { // 닫는 괄호이면 1. 스택이 비어있는지 2. top이 짝이 맞는 여는 괄호가 맞는지 확인
                    if (!s.empty() && s.top() == '(') s.pop();
                    else {
                        flag = 0;
                        break;
                    } 
                }
                else if (str[i] == ']') {
                    if (!s.empty() && s.top() == '[') s.pop();
                    else {
                        flag = 0; 
                        break;
                    }
                }
            }
            if (s.empty() && flag == 1) {
                cout << "yes\n";
            } else {
                cout << "no\n";
            }
        }
    }
    
    return 0;
}
