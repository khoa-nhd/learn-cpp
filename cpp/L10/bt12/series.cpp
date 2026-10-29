#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, n, m;
ll mod;

ll nhan(ll x, ll y){
    if(y == 0) return 0;
    ll temp = nhan(x, y/2);
    temp += temp;
    temp %= mod;
    if(y % 2 == 0) return temp;
    return (x + temp) % mod;
}

ll mu(ll base, ll power){
    if(power == 0) return 1;
    ll temp = mu(base, power/2);
    temp = nhan(temp, temp);
    temp %= mod;
    if(power % 2 == 0) return temp;
    return nhan(temp, base) % mod;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SERIES.INP", "r", stdin);
    freopen("SERIES.OUT", "w", stdout);
    ll t;
    cin >> t;
    while(t--){
        cin >> a >> n >> m;
//         (a^(n+1) - 1) / (a-1)
        if(a == 0){
            cout << 1 % m << "\n";
            continue;
        }
        if(a == 1){
            cout << (n + 1) % m << "\n";
            continue;
        }
        if(m == 1){
            cout << 0 << "\n";
            continue;
        }
        ll b = a - 1;
        mod = b * m;
        ll tuso = (mu(a, n + 1) - 1%mod + mod) % mod;
        cout << tuso / b << "\n";
    }
    return 0;
}
