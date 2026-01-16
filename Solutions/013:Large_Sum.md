問題文:https://projecteuler.net/problem=13

# 解法
50桁の整数はlong longを用いてもオーバーフローしてしまう．そこで，文字列型の整数("1443"，"123456789012"など)2つを引数としてとり，その2つの整数の和を足し算の筆算の要領で下の桁から計算し，その計算結果を文字列型の整数で返す関数large_sumを用意して，それを用いて最終的な和を求める．    
最終的な計算結果の上10桁を解答すればよい．

``` C++
#include <iostream>
#include <algorithm>
using namespace std;

string large_sum(string A, string B) {
    //受け取った文字列の先頭に適切に0を付け足すことで，文字列の長さを一致させる
    string S = "";
    for (int i = 0; i < abs((int)A.size() - (int)B.size()); i++) {
        S += "0";
    }
    
    if ((int)A.size() < (int)B.size()) {
        A = S + A;
    }
    else {
        B = S + B;
    }

    //下の桁から和を計算
    int c = 0;
    string C = "";
    for (int i = 0; i < (int)A.size(); i++) {
        int N = (A[(int)A.size() - 1 - i] - '0') + (B[(int)A.size() - 1 - i] - '0') + c;
        c = N / 10;
        C += (char)((N % 10) + '0');
    }
    if (c != 0) {
        C += (char)(c + '0');
    }
    reverse(C.begin(), C.end());
    return C;
}

int main() {
    string ans = "0";
    for (int i = 0; i < 100; i++) {
        string S;
        cin >> S;
        ans = large_sum(ans, S);
    }

    cout << ans << endl;
}
```
