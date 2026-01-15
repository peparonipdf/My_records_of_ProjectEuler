問題文:https://projecteuler.net/problem=9

# 解法
1 <= a < b < c < 1000 かつ a + b + c = 1000 なる整数の組(a, b, c)すべてについて，a^2 + b^2 = c^2 が成り立つかを調べればよい．  
c = 1000 - a - b であることを用いれば，2重for文で全探索ができる．

``` C++
#include <iostream>
using namespace std;

int main() {
    for (int a = 1; a < 1000; a++) {
        for (int b = a + 1; b < 1000 - a; b++) {
            if (a * a + b * b == (1000 - a - b) * (1000 - a - b)) {
                cout << a * b * (1000 - a - b) << endl;
            }
        }
    }
}
```
