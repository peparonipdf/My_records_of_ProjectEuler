問題文:https://projecteuler.net/problem=12

# 解法
各三角数について，約数の個数を実際に割り算をすることで求めるのは時間がかかりそう．  
対象の自然数を素因数分解し、各素因数の指数に1を足して掛け合わせることでも約数の個数を求められるため，その方法を用いる．  
あらかじめ，N = 1000000以下の素数を格納した配列primesを用意する．i番目の三角数MはM = i(i + 1) / 2で計算できることに注意して，配列primesを用いて各三角数について約数の個数を計算する．  
この場合，N - 1番目の三角数までに約数が500個以上の最小の三角数が存在しなければ何も出力せずにプログラムが終了するが，今回は答えの値が出力されるのでOK．

``` C++
#include <iostream>
#include <vector>
using namespace std;

void make_primelist(long long N, vector<int> &primes) { //N以下の素数がすべて格納された配列を作成
    vector<bool> isprime(N + 1, true);
    isprime[0] = false;
    isprime[1] = false;
    for (long long i = 2; i * i <= N; i++) { //N以下の自然数すべてについて素数判定
        if (isprime[i]) {
            for (long long j = 2; i * j <= N; j++) {
                isprime[i * j] = false;
            }
        }
    }
    for (int i = 0; i <= N; i++) { //N以下の素数を小さい順にprimesに格納
        if (isprime[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    int N = 1000000;
    vector<int> primes;
    make_primelist(N, primes);

    for (long long i = 1; i + 1 <= N; i++) { //素数判定はNまでしか行っていないため，正確に約数を計算できるのはi + 1 <= Nのときに限る
        int d = 1; //i番目の三角数の約数の個数(1で初期化)
        long long M = i * (i + 1) / 2; //i番目の三角数
        for (int j : primes) { //dの計算
            if (M % j == 0) {
                int count = 0;
                while (M % j == 0) {
                    M /= j;
                    count++;
                }
                d *= (count + 1);
            }
            if (M == 1) {
                break;
            }
        }

        if (d >= 500) {
            cout << i * (i + 1) / 2 << endl;
            return 0;
        }
    }
}
```
