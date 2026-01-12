問題文:https://projecteuler.net/problem=87

# 解法
一般に，正整数nについて，n=p^2+q^3+r^4となるような素数p,q,rが存在するか判定するにはやや時間がかかる．  
そこで，任意の素数p,q,rについて，p^2+q^3+r^4が50000000未満であるときにp^2+q^3+r^4をsetに入れ，最終的にsetの要素数を出力することにすれば，答えが得られる．  
特に，7071が2乗すると50000000以下となる最大の整数，368が3乗すると50000000以下になる最大の整数，84が4乗すると50000000以下になる最大の整数だから，それらの範囲にある素数について全探索をすればよい．

``` C++
#include <iostream>
#include <vector>
#include <set>
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
    vector<bool> isprime(7072, true);
    vector<long long> primes;
    furui(7071, isprime);
    int count_1 = 0;
    int count_2 = 0;
    for (int i = 0; i <= 7071; i++) {
        if (isprime[i]) {
            if (i <= 84) {
                count_2++;
            }
            if (i <= 368) {
                count_1++;
            }
            primes.push_back(i);
        }
    }
    
    set<long long> S;
    for (int i = 0; i < (int)primes.size(); i++) {
        for (int j = 0; j < count_1; j++) {
            for (int k = 0; k < count_2; k++) {
                long long x = primes[i] * primes[i] + primes[j] * primes[j] * primes[j] + primes[k] * primes[k] * primes[k] * primes[k];
                if (x < 50000000) {
                    S.insert(x);
                }
            }
        }
    }

    cout << (int)S.size() << endl;
}
```
