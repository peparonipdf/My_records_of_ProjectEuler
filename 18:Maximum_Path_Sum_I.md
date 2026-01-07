問題文:https://projecteuler.net/problem=18

# 解法
全探索でも解くことができるが，動的計画法を用いて計算する．  


``` C++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<vector<int>> input(15, vector<int>(15));
    for (int i = 0; i < 15; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> input[i][j];
        }
    }

    vector<vector<int>> dp(15, vector<int>(15));
    dp[0][0] = input[0][0];
    for (int i = 1; i < 15; i++) {
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

    sort(dp[14].begin(), dp[14].end());

    cout << dp[14][14] << endl;
}
```
