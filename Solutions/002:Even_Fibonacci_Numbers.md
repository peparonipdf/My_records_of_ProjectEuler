問題文:https://projecteuler.net/problem=2

# 解法
実際にFibonacci数列を計算し，4000000未満の偶数の項の総和を計算すればよい．  
何項目に初めて値が4000000以上となるかがわからないため，配列Fibの宣言時に要素数を指定しない方法を用いた．

``` C++
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> Fib;
    Fib = {1, 2}; //Fibonacci数列のi項目は，i項目の前2つの項に依存して決まるため，最初の2項で配列Fibを初期化

    long long sum = 0;
    for (int i = 0; ; i++) {
        if (Fib[i] >= 4000000) {
            break; //Fib[i]が4000000以上の時，繰り返し処理から抜ける
        }
        Fib.push_back(Fib[i] + Fib[i + 1]); //Fibonacci数列のi+2項目を計算し，配列Fibの末尾に追加
        if (Fib[i] % 2 == 0) {
            sum += Fib[i]; //Fib[i]が偶数のとき，sumにFib[i]を加算
        }
    }

    cout << sum << endl; //sumを出力
}
```
