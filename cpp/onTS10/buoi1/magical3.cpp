#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

ll sol(){
    n -= 3;
    ll res = LLONG_MAX;
    for(ll i = 1; i * i <= n; ++i){
        if(n % i == 0){
            ll mot = i;
            ll hai = n / i;
            if(mot > 3) res = min(res, mot);
            if(hai > 3) res = min(res, hai);
        }
    }
    return res;
}

int main(){
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    cin >> n;
    ll res;
    res = sol();
    cout << res;
    return 0;
}
