問題文:https://projecteuler.net/problem=4

# 解法
対称性に着目すると，100 <= i <= j < 1000なる整数の組(i, j)すべてについてi * jが回文数となるか判定し，回文数であるようなi * jの値の最大値を出力すればよいことがわかる．

``` C++
#include <iostream>
using namespace std;

int main() {
    int ans = 0;
    for (int i = 100; i < 1000; i++) {
        for (int j = i; j < 1000; j++) {
            string S = to_string(i * j);
            for (int k = 0; k < (int)S.size(); k++) {
                if (S[k] != S[(int)S.size() - 1 - k]) {
                    break;
                }
                if (k == (int)S.size() - 1) {
                    ans = max(ans, i * j);
                }
            }
        }
    }

    cout << ans << endl;
}
```
