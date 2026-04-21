#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a, b, c;

ll calDuoi(ll t){
    ll lo = 0, hi = t;
    ll res = -1;
    while(lo <= hi){
        ll half = (lo + hi) / 2;
        if(a * half <= c * t + b * (t - half - 1)){
            res = half;
            lo = half + 1;
        } else{
            hi = half - 1;
        }
    }
    ll ans = c * t + b * (t - res -1);
    if(res < t) ans = min(ans, a * (res + 1));
    return ans;
}

ll lift(){
    ll lo = 0, hi = n;
    ll res = -1;
    while(lo <= hi){
        ll half = (lo + hi) / 2;
        ll duoi = calDuoi(half);
        if(duoi <= c*half + a*(n-half)){
            res = half;
            lo = half + 1;
        } else{
            hi = half - 1;
        }
    }
    ll ans = c*res + a*(n-res);
    if(res < n) ans = min(ans, calDuoi(res + 1));
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("LIFT.INP", "r", stdin);
    freopen("LIFT.OUT", "w", stdout);
    cin >> n >> a >> b >> c;
    ll res;
    res = lift();
    cout << lift();
    return 0;
}
