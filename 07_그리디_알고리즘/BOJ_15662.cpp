#include <iostream>
#include <vector>
#include <deque>

using namespace std;

typedef vector<deque<int>> cards;
const int DO = 0, SU = 1;


void transferCards(deque<int>& deck, deque<int>& ground) {
    while (!ground.empty()) {
        deck.push_back(ground.back());
        ground.pop_back();
    }
}


int canRingBell(const cards& ground) {
    if (!ground[DO].empty() && ground[DO].front() == 5) { // 하나만 5일 때
        return DO;
    }
    if (!ground[SU].empty() && ground[SU].front() == 5) { // 하나만 5일 때
        return DO;
    }
    if (!ground[DO].empty() && !ground[SU].empty() && ground[DO].front() + ground[SU].front() == 5) { // 합이 5일 때
        return SU;
    }
    return -1;
}


string game(int m, cards& deck, cards& ground) {
    bool turn = DO; // 도도부터 시작
    while (m--) {
        ground[turn].push_front(deck[turn].front()); // 카드를 내려놓음
        deck[turn].pop_front(); // 내려놓은 카드를 삭제
        
        if (deck[turn].empty()) { // 덱이 비면 종료
            break;
        }

        int bell = canRingBell(ground); // 종을 칠 수 있는지 확인
        if (bell != -1) { // 종을 친 경우
            transferCards(deck[bell], ground[!bell]); // 상대 그라운드와 본인 그라운드를 자기 덱으로
            transferCards(deck[bell], ground[bell]); 
        }

        turn = !turn; // 차례 변경
    }

    if (deck[DO].size() > deck[SU].size()) {
        return "do";
    }
    if (deck[DO].size() < deck[SU].size()) {
        return "su";
    }
    return "dosu";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    // 입력
    int n, m, card1, card2;
    cards deck(2), ground(2);

    cin >> n >> m;
    while (n--) {
        cin >> card1 >> card2;
        deck[DO].push_front(card1);
        deck[SU].push_front(card2);
    }

    // 출력
    cout << game(m, deck, ground);

    return 0;
}