問題文:https://projecteuler.net/problem=8

# 解法
1000桁の数字を文字列Nとして受け取り，長さ13の連続するNの部分文字列すべてについて，問題文の通りに積を計算し，それらの最大値を求めればよい．  
問題文に書かれている数字は50桁の数字20個に小分けにされているので，入力の受け取り方はそれをふまえたものにする必要がある．

``` C++
#include <iostream>
using namespace std;

int main() {
    string N = "";
    for (int i = 0; i < 20; i++) {
        string T;
        cin >> T;
        N += T;
    }

    long long ans = 0;
    for (int i = 0; i < 988; i++) {
        long long cmp = 1;
        for (int j = 0; j < 13; j++) {
            cmp *= (N[i + j] - '0');
        }
        ans = max(ans, cmp);
    }

    cout << ans << endl;
}
```
