問題文:https://projecteuler.net/problem=29

# 解法
Problem 16で作った関数large_prodを用いて，2 <= a, b <= 100なる正整数の組(a, b)すべてについてa^bを実際に計算し，それらをsetに入れて，最終的にsetの要素数を出力すればよい．

``` C++
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

string large_prod(string A, string B) {
    int c = 0;
    string C = "";
    for (int i = 0; i <= (int)A.size() + (int)B.size() - 2; i++) {
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

    reverse(C.begin(), C.end());
    return C;
}

int main() {
    set<string> S;
    for (int a = 2; a <= 100; a++) {
        for (int b = 2; b <= 100; b++) {
            string tar = "1";
            for (int i = 0; i < b; i++) { //a^bを計算
                tar = large_prod(tar, to_string(a));
            }
            S.insert(tar);
        }
    }
    cout << (int)S.size() << endl;
}
```
