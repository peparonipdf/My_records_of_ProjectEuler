#解法
3の倍数または5の倍数であるような1000より小さい自然数をすべて足し合わせる．  
for文を使い，1から999までのすべての自然数について，3か5で割り切れるかを確認すればよい．

'''#include <iostream>
using namespace std;

int main() {
    long long ans = 0;
    for (int i = 1; i < 1000; i++) {
        if (i % 3 == 0 or i % 5 == 0) {
            ans += i;
        }
    }

    cout << ans << endl;
}'''
