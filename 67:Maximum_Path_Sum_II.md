問題文:https://projecteuler.net/problem=67

# 解法

``` C++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<vector<int>> input(100, vector<int>(100));
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> input[i][j];
        }
    }

    vector<vector<int>> dp(100, vector<int>(100));
    dp[0][0] = input[0][0];
    for (int i = 1; i < 100; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                dp[i][j] = dp[i - 1][j] + input[i][j];
            }
            else if (j == i) {
                dp[i][j] = dp[i - 1][j - 1] + input[i][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + input[i][j];
            }
        }
    }

    sort(dp[99].begin(), dp[99].end());

    cout << dp[99][99] << endl;
}
```
