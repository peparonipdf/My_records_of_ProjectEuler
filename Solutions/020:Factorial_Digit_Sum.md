問題文:https://projecteuler.net/problem=20

# 解法
Problem 16で用いた関数large_prodを用いて100!を計算し，各桁の和を求めればよい．

``` C++
#include <iostream>
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
    string tar = "1";
    for (int i = 1; i <= 100; i++) { //100!を計算
        tar = large_prod(tar, to_string(i));
    }
    int ans = 0;
    for (int i = 0; i < (int)tar.size(); i++) { //100!の各桁の和を計算
        ans += tar[i] - '0';
    }
    cout << ans << endl;
}
```
