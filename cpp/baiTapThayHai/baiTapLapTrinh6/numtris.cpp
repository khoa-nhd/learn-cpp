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
// công thức tính cộng lũy thừa cùng cơ số.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t, n;
ll soMod = 1e9 + 7;

ll nhan(ll x, ll y){
    if(y == 0) return 0;
    if(y % 2 == 0) return 2 * nhan(x, y/2) % soMod;
    else return x + nhan(x, y-1) % soMod;
}

ll mu(ll base, ll power){
    if(power == 0) return 1;
    ll temp = mu(base, power/2);
    temp = nhan(temp, temp);
    if(power % 2 == 0) return temp;
    else return nhan(base, temp);
}

ll numtris(){
    if(n == 1) return 1;
    ll res = 0;
    res += mu(3, n-1);
    res += nhan(2, (mu(3, n-1) - 1) / 2);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("NUMTRIS.INP", "r", stdin);
    freopen("NUMTRIS.OUT", "w", stdout);
    cin >> t;
    for(int i = 0; i < t; ++i){
        cin >> n;
        n += 1;
        ll res;
        res = numtris();
        cout << res << "\n";
    }
    return 0;
}
