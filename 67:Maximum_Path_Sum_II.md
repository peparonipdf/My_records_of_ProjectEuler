問題文:https://projecteuler.net/problem=67

# 解法
動的計画法を用いて解く．  
問題文中で与えられた三角形状に並んだ数字の羅列の上からi段目の左からj番目の数字をinput[i-1][j-1]とし，input[0][0]から始まり，input[i][j]に至るまでの数字の和の最大値をdp[i][j]とする．このとき，dp[0][0]=input[0][0]=59であり，j=0のときdp[i][j]=dp[i-1][j]+input[i][j]，j=iのときdp[i][j]=dp[i-1][j-1]+input[i][j]，j≠0,iのときdp[i][j]=max(dp[i-1][j], dp[i-1][j-1])+input[i][j]と計算できる．  
これを用いて任意の0<=j<=99についてdp[99][j]を計算し，それらの最大値を求めればよい．


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
