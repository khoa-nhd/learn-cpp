#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ull a, b, k;

ull maxx(ull n){
    ll res = -1;
    ll lo = 1, hi = sqrt(n)+1;
    while(lo <= hi){
        ull half = (lo + hi) / 2;
        ll val = half * half;
        if(val <= n){
            res = half;
            lo = half + 1;
        } else{
            hi = half - 1;
        }
    }
    return res;
}

ull kdensity(){
    ull res = 0;
    for(ull y = 1; y <= 1e6; ++y){
        if(y*y*y < a) continue;
        if(y*y*y > b) break;
        ll mot = maxx(min(y*y*y + k, b));
        ll hai;
        if((ll)((ll)y*y*y - (ll)k - (ll)1) < 0){
            hai = maxx(a-1);
        } else hai = maxx(max(a-1, y*y*y - k - 1));
        mot = max(0LL, mot);
        hai = max(0LL, hai);
        res += mot - hai;
    }
    return res;
}

int main(){
    freopen("KDENSITY.INP", "r", stdin);
    freopen("KDENSITY.OUT", "w", stdout);
    cin >> a >> b >> k;
    ll res;
    res = kdensity();
    cout << res;
    return 0;
}
