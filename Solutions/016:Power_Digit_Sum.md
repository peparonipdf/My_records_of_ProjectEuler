問題文:https://projecteuler.net/problem=16

# 解法
普通に2^1000を計算しても，long longを用いたとしてもオーバーフローしてしまう．  
そこで，積が大きくなっても対応できるように，文字列を用いて，筆算の要領で積を計算する関数large_prodを用意し，それを用いて2^1000を計算する．  
2^1000を計算した後，積の計算結果の文字列を走査して，各桁の和を求めればよい．

``` C++
#include <iostream>
#include <algorithm>
using namespace std;

string large_prod(string A, string B) { //積を計算
    int c = 0; //繰り上がり
    string C = "";
    for (int i = 0; i <= (int)A.size() + (int)B.size() - 2; i++) { //筆算の要領で積を下の桁から計算
        int tmp = 0;
        for (int j = 0; j <= i; j++) {
            if (j < (int)A.size() and (i - j) < (int)B.size()) {
                tmp += (A[(int)A.size() - 1 - j] - '0') * (B[(int)B.size() - 1 - (i - j)] - '0');
            }
        }
        tmp += c;
        C += to_string(tmp % 10);
        c = tmp / 10;
    }
    if (c != 0) {
        C += to_string(c);
    }

    reverse(C.begin(), C.end()); //積の計算を下の桁から行っていたので，最後に文字列を反転させる．
    return C;
}

int main() {
    string tar = "1";
    for (int i = 0; i < 1000; i++) { //2^1000を計算
        tar = large_prod(tar, "2");
    }
    int ans = 0;
    for (int i = 0; i < (int)tar.size(); i++) { //2^1000の各桁の和を計算
        ans += tar[i] - '0';
    }
    cout << ans << endl;
}
```
