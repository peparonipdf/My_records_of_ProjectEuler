問題文:https://projecteuler.net/problem=81

# 解法
問題文に添付されているテキストファイルの","が邪魔なので，まず","を" "に置き換えるコードを書いた．

``` C++
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> T(80, "");
    for (int i = 0; i < 80; i++) {
        string S;
        cin >> S;
        for (int j = 0; j < (int)S.size(); j++) {
            if (S[j] == ',') {
                T[i] += ' ';
            }
            else {
                T[i] += S[j];
            }
        }
    }

    for (int i = 0; i < 80; i++) {
        cout << T[i] << endl;
    }
}
```

この問題はProblem 18などと同様に，動的計画法で解くことができる．  
入力を受け取る80×80の配列をinputとする．  
80×80の配列dpを用意し，  
i = j = 0 のときdp[i][j] = input[i][j]，  
i = 0 かつ j ≠ 0 のときdp[i][j] = dp[i][j - 1] + input[i][j]，  
i ≠ 0 かつ j = 0 のときdp[i][j] = dp[i - 1][j] + input[i][j]，  
i ≠ 0 かつ j ≠ 0 のときdp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + input[i][j]  
によって定めると，dp[79][79]が答えとなる．  
先ほどのコードを用いて，添付されたテキストファイルの","を" "で置き換えたものを入力で与えれば，答えを得られる．

``` C++
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<vector<int>> input(80, vector<int>(80)), dp(80, vector<int>(80));

    //入力の受け取り
    for (int i = 0; i < 80; i++) {
        for (int j = 0; j < 80; j++) {
            cin >> input[i][j];
        }
    }

    //配列dpの各要素を計算
    for (int i = 0; i < 80; i++) {
        for (int j = 0; j < 80; j++) {
            if (i == 0) {
                if (j == 0) {
                    dp[i][j] = input[i][j];
                }
                else {
                    dp[i][j] = dp[i][j - 1] + input[i][j];
                }
            }
            else {
                if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + input[i][j];
                }
                else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + input[i][j];
                }
            }
        }
    }

    //dp[79][79]が答え
    cout << dp[79][79] << endl;
}
```
