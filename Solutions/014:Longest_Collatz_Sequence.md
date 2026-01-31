問題文:https://projecteuler.net/problem=14

# 解法
与えられた漸化式に基づいて，1以上1000000未満の整数について実際に計算を行えばよいが，オーバーフローが途中で起こりえないか確認する必要があることに注意．

``` C++
#include <iostream>
using namespace std;

int main() {
    int max_count = 0;
    int ans = -1;
    for (int i = 1; i < 1000000; i++) {
        long long N = i;
        int count = 1;
        while (N != 1) {
            if (N % 2 == 0) {
                N /= 2;
            }
            else {
                N = 3 * N + 1;
            }
            count++;
            if (N >= 100000000000000000) { //オーバーフロー対策．Nが10^17を超えたとき処理を打ち切る(今回は処理は打ち切られない)
                cout << "warning" << endl;
                return 0;
            }
        }

        if (count > max_count) {
            max_count = count;
            ans = i;
        }
    }

    cout << ans << endl;
}
```
