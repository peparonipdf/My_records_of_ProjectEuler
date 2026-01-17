問題文:https://projecteuler.net/problem=74

# 解法
整数iが1 <= i < 1000000 を満たすとする．まずsetにiを入れる．その後，以下のような繰り返し処理をする．  
・iの各桁の階乗の和sumを計算し，sumがsetに含まれていなかったらsetにsumを入れi = sumとする．sumがsetに含まれていたら繰り返し処理を終了する．  
繰り返し処理が終わった後に，setの要素数が60となるようなiの個数を求めればよい．  
階乗はいちいち計算していると時間がかかるため，あらかじめ0!から9!までの値を計算した配列factを用意した．

``` C++
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int ans = 0;
    vector<int> fact = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

    for (int i = 1; i < 1000000; i++) {
        set<int> S;
        S.insert(i);
        int N = i;
        while (true) {
            int sum = 0;
            while (N > 0) {
                sum += fact[N % 10];
                N /= 10;
            }
            if (S.count(sum)) {
                break;
            }
            else {
                S.insert(sum);
                N = sum;
            }
        }
        if ((int)S.size() == 60) {
            ans++;
        }
    }

    cout << ans << endl;
}
```
