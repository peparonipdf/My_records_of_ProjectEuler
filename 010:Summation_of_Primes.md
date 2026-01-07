問題文:https://projecteuler.net/problem=10

# 解法
1<=i<=2000000なるすべての整数iについて素数かどうかを判定し，総和を計算する．  
素数の判定にはエラトステネスの篩を用いた．

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
    vector<bool> isprime(2000001, true);
    furui(2000000, isprime);
    long long sum = 0;
    for (int i = 0; i < 2000000; i++) {
        if (isprime[i]) {
            sum += i;
        }
    }
    cout << sum << endl;
}
```
