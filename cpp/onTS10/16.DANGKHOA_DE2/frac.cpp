#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;

ll cnt(ll q){
    ll nn = n + q;
    ll mm = m + m - 1;
    return (mm / nn) - (m / nn);
}

ll frac(){
    ll res = 0;
    for(int i = 1; i < n; ++i){
        res += cnt(i);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("FRAC.INP", "r", stdin);
    freopen("FRAC.OUT", "w", stdout);
    cin >> m >> n;
    ll res = 0;
    res = frac();
    cout << res;
    return 0;
}
