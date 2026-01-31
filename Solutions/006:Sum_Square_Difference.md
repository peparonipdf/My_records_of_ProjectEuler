問題文:https://projecteuler.net/problem=6

# 解法
Σ(1 <= k <= n)k^2 = n(n + 1)(2n + 1) / 6であり，(Σ(1 <= k <= n)k)^2 = (n(n + 1) / 2)^2 だから，  
n^2 (n + 1)^2 / 4 - n(n + 1)(2n + 1) / 6 に n = 100を代入した値が答え．

``` C++
#include <iostream>
using namespace std;

int calc(int N) {
    return N * N * (N + 1) * (N + 1) / 4 - N * (N + 1) * (2 * N + 1) / 6;
}

int main() {
    cout << calc(100) << endl;
}
```
