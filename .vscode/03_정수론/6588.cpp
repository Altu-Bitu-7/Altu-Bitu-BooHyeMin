#include <iostream>
#include <vector>

const int MAX = 1000000;
using namespace std;

vector<int> getPrimes() { // 소수
    vector<int> primes(MAX + 1, 1);

    for (int i = 3; i * i <= MAX; i++) { // 짝수를 고려하지 않음
        if (primes[i] == 0) {
            continue;
        }

        for (int j = i * i; j <= MAX; j += i) {
            primes[j] = 0;
        }
    }
    
    return primes;
}

int getPrimeFactors(int n, vector<int> &primes) {

    for (int a = 3; a <= n / 2; a += 2) { // 짝수를 고려하지 않음
        int b = n - a;
        if (primes[a] != 0 && primes[b] != 0) { // a, b가 둘 다 소수일 때 반환        
            return a;
        }
    } 
    return 0;   
}

int main() {

    vector<int> primes = getPrimes();

    while (true) {
        ios::sync_with_stdio(false);
        cin.tie(NULL); cout.tie(NULL);

        int n;
        cin >> n;

        if (n == 0) {
            break;
        }
        
        int a = getPrimeFactors(n, primes);

        if (a == 0) {
            cout << "Goldbach's conjecture is wrong.\n";
        } else {
            cout << n << " = " << a << " + " << n - a << "\n";           
        }
    }

    return 0;
}
