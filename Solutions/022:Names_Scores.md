問題文:https://projecteuler.net/problem=22

# 解法
まず，添付されたテキストファイルの"と,が邪魔であり，またテキストファイルに含まれる単語数がわからないため，"を用いて単語数を数えて,を空白で置き換えるコードを書いた．

``` C++
#include <iostream>
using namespace std;

int main() {
    string S;
    cin >> S;
    string T = "";

    int count = 0;
    for (int i = 0; i < (int)S.size(); i++) {
        if (S[i] == '"') {
            count++;
        }
        else if (S[i] == ',') {
            T += ' ';
        }
        else {
            T += S[i];
        }
    }

    cout << T << endl;
    cout << count / 2 << endl; //単語数は"の個数/2
}
```

上のプログラムを実行した結果，単語数は5163個あることがわかった．  
このことを踏まえて，問題文の指示通りに答えを求めればよい．  
各名前のスコアは，文字コードを用いて計算した．

``` C++
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> S(5163);
    for (int i = 0; i < 5163; i++) {
        cin >> S[i];
    }

    sort(S.begin(), S.end());

    long long ans = 0;
    for (int i = 0; i < 5163; i++) {
        long long tmp = 0;
        for (int j = 0; j < (int)S[i].size(); j++) {
            tmp += (S[i][j] - 'A' + 1);
        }
        ans += (i + 1) * tmp;
    }

    cout << ans << endl;
}
```
