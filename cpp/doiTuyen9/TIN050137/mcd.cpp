#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b;
map<ll, ll> m;

void phantich(ll x){
    for(ll i = 1; i * i <= x; ++i){
        if(i * i == x) m[i] += 1;
        if(x % i == 0){
            m[i] += 1;
            m[x / i] += 1;
        }
    }
}

ll tongchuso(ll x){
    ll res = 0;
    while(x > 0){
        res += x % 10;
        x /= 10;
    }
    return res;
}

ll mcd(){
    phantich(a);
    phantich(b);
    ll res = 0;
    for(auto x : m){
        if(x.second == 2){
            res = max(res, tongchuso(x.first));
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MCD.INP", "r", stdin);
    freopen("MCD.OUT", "w", stdout);
    cin >> a >> b;
    ll res;
    res = mcd();
    cout << res;
    return 0;
}
