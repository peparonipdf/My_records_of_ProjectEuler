問題文:https://projecteuler.net/problem=92

# 解法
問題文に書いてある通りに，1以上10000000未満のすべての整数についてwhile文を用いてシミュレーションをすればよい．  
各桁の2乗の値の総和を求める際には，整数を文字列型に変換し，for文を用いて計算をしている．

``` C++
#include <iostream>
using namespace std;

int main() {
    int ans = 0;
    for (int i = 1; i < 10000000; i++) {
        string N = to_string(i);
        while (true) {
            int next = 0;
            for (int i = 0; i < (int)N.size(); i++) {
                next += (N[i] - '0') * (N[i] - '0');
            }
            if (next == 1) {
                break;
            }
            else if (next == 89) {
                ans++;
                break;
            }
            else {
                N = to_string(next);
            }
        }
    }

    cout << ans << endl;
}
```
