問題文:https://projecteuler.net/problem=91

# 解法
Pの座標を(x,y)，Qの座標を(z,w)とする．  
3点O,P,Qが同一直線上に並ばないことは，△OPQの面積が0でないことと同値であり，特にxw≠yzであることと同値である．  
角Oが直角であることは，(x,y)と(z,w)の内積が0であること，すなわちxz+yw=0であることと同値である．同様にして内積に着目すると，
角Pが直角であることはx(z-x)+y(w-y)=0であることと同値であり，角Qが直角であることはz(x-z)+w(y-w)=0であることと同値であることがわかる．  
これらのことを用いて全探索による数え上げを行えばよいが，△OPQが直角三角形のとき△OQPも直角三角形であることから，数え上げによって求めた値を最終的に2で割る必要があることに注意．

``` C++
#include <iostream>
using namespace std;

int main() {
    long long ans = 0;
    for (int x = 0; x <= 50; x++) {
        for (int y = 0; y <= 50; y++) {
            for (int z = 0; z <= 50; z++) {
                for (int w = 0; w <= 50; w++) {
                    if (y * z != x * w) {
                        if (x * z + y * w == 0) {
                            ans++;
                        }
                        else if (x * (z - x) + y * (w - y) == 0) {
                            ans++;
                        }
                        else if (z * (x - z) + w * (y - w) == 0) {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout << ans / 2 << endl;
}
```

また，直角の存在判定は三平方の定理を用いてもできる．  
{a, b, c}の最小値をA，最大値をC，a + b + c - A - C = Bとする．三平方の定理が成立するか調べるにはA + B = Cが成立するか調べればよいが，これを式変形すると，結局2 * max({a, b, c}) = a + b + cを満たすかどうか判定すればよいことがわかる．

``` C++
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long ans = 0;
    for (int x = 0; x <= 50; x++) {
        for (int y = 0; y <= 50; y++) {
            for (int z = 0; z <= 50; z++) {
                for (int w = 0; w <= 50; w++) {
                    if (y * z != x * w) {
                        int a = x * x + y * y;
                        int b = z * z + w * w;
                        int c = (x - z) * (x - z) + (y - w) * (y - w);
                        if (2 * max({a, b, c}) == a + b + c) {
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout << ans / 2 << endl;
}
```
