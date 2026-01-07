問題文:https://projecteuler.net/problem=18

# 解法
全探索でも解くことができるが，動的計画法を用いて計算する．  
問題文中で与えられた三角形状に並んだ数字の羅列の上からi段目の左からj番目の数字をinput[i-1][j-1]とし，input[0][0]から始まり，input[i][j]に至るまでの数字の和の最大値をdp[i][j]とする．このとき，dp[0][0]=input[0][0]=75であり，j=0のときdp[i][j]=dp[i-1][j]+input[i][j]，j=iのときdp[i][j]=dp[i-1][j-1]+input[i][j]，j≠0,iのときdp[i][j]=max(dp[i-1][j], dp[i-1][j-1])+input[i][j]と計算できる．
これを用いて任意の0<=j<=14についてdp[14][j]を計算し，それらの最大値を求めればよい．

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
