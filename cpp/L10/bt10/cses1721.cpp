#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m = 1e9 + 7;

ll mu(ll base, ll power, ll mod){
    if(power == 0) return 1;
    ll temp = mu(base, power / 2, mod);
    temp *= temp;
    temp %= mod;
    if(power % 2 == 0) return temp;
    else return (temp * base) % mod;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    ll a, b, c;
    ll n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a >> b >> c;
        a %= m;
        b %= m;
        c %= m;
        cout << mu(a, mu(b, c, m - 1), m) << "\n";
    }
    return 0;
}
