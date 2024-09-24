#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int len = number.length() - k; // 최종 숫자의 길이
    
    int idx = 0;
    for (int i = 0; i < len; i++) {
        char max = '0';
        for (int j = idx; j <= k + i; j++) { // idx ~ k+1에서 가장 큰 숫자 선택
            if (number[j] > max) {
                max = number[j];
                idx = j + 1; // 선택한 큰 숫자 위치 다음부터 탐색
            }
        }
        answer += max;
    }
    
   
    return answer;
}