//f(1) = 1
//f(n) = f(n-1) * 3 + 2
//
//1 : 1
//2 : 1 * 3 + 2
//3 : (1 * 3 + 2) * 3 + 2
//=> 1*3*3 + 2*3 + 2
//4 : ((1 * 3 + 2) * 3 + 2) * 3 + 2
//=> 1*3*3*3 + 2*3*3 + 2*3 + 2
//
//f(1) = 1
//f(n) = 3^(n-1) + 2*3^(n-2) + ... + 2*3^0
//= 3^(n-1) + 2*(3^0 + 3^1 +...+ 3^n-2)
//
//gọi 3^0 + 3^1 +...+ 3^n-2 = s
//3s = 3^1 + 3^2 + ... + 3^n-1
//3s - s = 3^1 + 3^2 + ... + 3^n-1 - 3^0 + 3^1 +...+ 3^n-2
//s(3-1) = (3^n-1 - 3^0)
//s = (3^n-1 - 3^0) / 2
//
//=> fn = 3^(n-1) + 2*((3^n-1 - 3^0) / 2)
//=> fn = 3^(n-1)*2 - 1
// công thức tính cộng lũy thừa cùng cơ số.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll t, n;
ll soMod = 1e9 + 7;
ll dem = 0;

ll mu(ll base, ll power){
//    dem += 1;
    if(power == 0) return 1;
    ull temp = mu(base, power/2) % soMod;
    temp = temp * temp;
    temp %= soMod;
    if(power % 2 == 0) return temp;
    else return ((base % soMod) * temp) % soMod;
}

ll numtris(){
    ull res = 0;
    res += ((ull)mu(3, n) * (ull)2) % soMod;
    res -= 1;
//    cout << dem << "\n";
    return res % soMod;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("NUMTRIS.INP", "r", stdin);
    freopen("NUMTRIS.OUT", "w", stdout);
    cin >> t;
    for(int i = 0; i < t; ++i){
        cin >> n;
        ll res;
        res = numtris();
        cout << res << "\n";
    }
//        cout << dem << "\n";
    return 0;
}
