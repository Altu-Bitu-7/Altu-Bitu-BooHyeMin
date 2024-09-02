#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {

    int w, intake0, t; // 체중, 다이어트 전 일일 에너지 섭취량 (일일 기초 대사량), 기초 대사량 변화 역치
    int d, intake1, activemr; // 다이어트 기간, 다이어트 기간 일일 에너지 섭취량, 다이어트 기간 일일 활동 대사량
    
    // 입력
    cin >> w >> intake0 >> t;
    cin >> d >> intake1 >> activemr;

    // 체중과 기초 대사량의 변화를 저장하기 위한 변수 설정
    int bmr1 = intake0, bmr2 = intake0;
    int w1 = w, w2 = w;

    for (int i = 1; i <= d; i++) {
        w1 += intake1 - (bmr1 + activemr); // 일일 기초 대사량의 변화를 고려하지 않았을 때의 예상 체중
        w2 += intake1 - (bmr2 + activemr); // 일일 기초 대사량의 변화를 고려하였을 때의 예상 체중

        if (abs(intake1 - (bmr2 + activemr)) > t) {
            bmr2 += floor((intake1 - (bmr2 + activemr)) / 2.0); 
            // -5/2 = -3과 같은 계산을 수행하기 위해 floor()를 사용
        }
    }

    if (w1 <= 0) { 
        // 첫 줄에 "Danger Diet"가 출력되려면 일일 기초 대사량의 변화를 고려하지 않았을 때의 체중이 0이하가 되는 경우밖에 없음 
        cout << "Danger Diet" << endl;
    } else {
        cout << w1 << " " << bmr1 << endl;
    }

    if (w2 <= 0 || bmr2 <= 0) {
        // 두 번째 줄에 "Danger Diet"가 출력되려면 일일 기초 대사량의 변화를 고려한 체중이 0 이하이거나, 일일 기초 대사량이 0Kcal 이하인 경우
        cout << "Danger Diet";
    } else {
        cout << w2 << " " << bmr2 << " ";
        if (bmr1 > bmr2) { // 요요의 여부는 기초 대사량을 비교하여야 함
            cout << "YOYO";
        } else {
            cout << "NO";
        }
    }
    
    return 0;
}
