問題文:https://projecteuler.net/problem=3

# 解法
2以上の整数iについて，iが小さい順に実際に600851475143がiで割り切れるかどうか確かめ，iで割り切れるときは，Nがiで割り切れなくなるまで，Nをiで割った商にNを更新することを繰り返す．  
この処理によってN = 1となったとき，その時のiの値がNを割り切る最大の素因数であることがわかるため，iを出力すればよい．

``` C++
#include <iostream>
using namespace std;

int main() {
    long long N = 600851475143;

    for (long long i = 2; i <= N; i++) {
        if (N % i == 0) {
            while (N % i == 0) {
                N /= i; //Nがiで割り切れるとき，Nがiで割り切れなくなるまで，Nをiで割った商にNを更新することを繰り返す
            }
        }
        if (N == 1) {
            cout << i << endl; //N=1となったときのiの値が答え
        }
    }
}
```
