#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sum_s(string s) {
    int sum = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] > 47 && s[i] < 58) {
            int num = s[i] - 48;
            sum += num;
        }
    }
    return sum;
}

bool cmp(const string& s1, const string& s2) {
    if (s1.size() != s2.size()) {
        return s1.size() < s2.size();
    }
    if (sum_s(s1) != sum_s(s2)) {
        return sum_s(s1) < sum_s(s2);
    }
    return s1 < s2;

}


int main() {
    int n;
    vector<string> serial;
    cin >> n;

    serial.assign(n, "");
    for (int i = 0; i < n; i++) {
        cin >> serial[i];
    }

    sort(serial.begin(), serial.end(), cmp);

    for (int i = 0; i < serial.size(); i++) {
        cout << serial[i] << endl;
    }
    
    return 0;
}
