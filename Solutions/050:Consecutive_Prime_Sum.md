問題文:https://projecteuler.net/problem=50

# 解法
1000000以下の素数が小さい順にすべて格納された配列primesを作成し，それを用いて和が1000000を超えないような連続する素数の個数としてありうる最大値Mの計算をする．
その後に，i <= Mなる正整数iについて，連続するi個の素数の和が1000000以下の素数となることがあるかどうかをiが大きい順に確かめればよい．

``` C++
#include <iostream>
#include <vector>
using namespace std;

void furui(long long N, vector<bool> &isprime) {
    isprime[0] = false;
    isprime[1] = false;
    for (long long i = 2; i * i <= N; i++) {
        if (isprime[i]) {
            for (long long j = 2; i * j <= N; j++) {
                isprime[i * j] = false;
            }
        }
    }
}

int main() {
    vector<bool> isprime(1000001, true);
    vector<int> primes;
    furui(1000000, isprime);
    for (int i = 0; i <= 1000000; i++) {
        if (isprime[i]) {
            primes.push_back(i);
        }
    }
    
    int sum = 0;
    int M = 0;
    for (int i = 0; i < (int)primes.size(); i++) {
        if (sum + primes[i] < 1000000) {
            sum += primes[i];
        }
        else {
            M = i;
            break;
        }
    }

    for (int i = M; i >= 0; i--) {
        for (int j = 0; ; j++) {
            sum = 0;
            for (int k = 0; k < i; k++) {
                sum += primes[j + k];
            }
            if (sum >= 1000000) {
                break;
            }
            else {
                if (isprime[sum]) {
                    cout << sum << endl;
                    return 0;
                }
            }
        }
    }
}
```
