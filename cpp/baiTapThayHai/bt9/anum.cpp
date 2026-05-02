#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll l, r;

ll revNum(ll x){
    ll res = 0;
    while(x > 0){
        res *= 10;
        res += x % 10;
        x /= 10;
    }
    return res;
}

ll num(ll x){
    ll res = 0;
    while(x > 0){
        res += 1;
        x /= 10;
    }
    return res;
}

ll anum(){
    ll res = 0;
    for(ll i = 0; i * i <= r; ++i){
        ll v = i * i;
        if(v >= l){
            ll rv = revNum(v);
            ll srv = sqrt(rv);
            if(srv * srv == rv && num(rv) == num(v)){
                res += 1;
//                cout << v << "\n";
            }
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ANUM.INP", "r", stdin);
    freopen("ANUM.OUT", "w", stdout);
    cin >> l >> r;
    ll res;
    res = anum();
    cout << res;
    return 0;
}
