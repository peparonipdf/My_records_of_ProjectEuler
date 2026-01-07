問題文:https://projecteuler.net/problem=97

# 解法
2^7830457の下10桁をNとし，28433*N+1を10000000000で割ったあまりを計算すればよい．  
2^7830457の下10桁の計算にはfor文を用いた．

``` C++
#include <iostream>
using namespace std;

int main() {
    long long ans = 1;
    for (int i = 0; i < 7830457; i++) {
        ans = (ans * 2) % 10000000000;
    }
    ans = (28433 * ans + 1) % 10000000000;

    cout << ans << endl;
}
```
