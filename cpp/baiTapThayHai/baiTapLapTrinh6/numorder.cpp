#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, k;

bool check(ll x){
    ll cnt = 0;
    for(int i = 1; i <= n; ++i){
        ll lo = 1;
        ll hi = m;
        ll num = 0;
        while(lo <= hi){
            ll half = (lo + hi) / 2;
            ll val = half*half + i*i;
            if(val > x){
                hi = half - 1;
            } else{
                lo = half + 1;
                num = half;
            }
        }
        cnt += num;
    }
    return cnt >= k;
}

ll numorder(){
    ll lo = 2;
    ll hi = n*n + m*m;
    ll res = -1;
    while(lo <= hi){
        ll half = (lo + hi) / 2;
        if(check(half)){
            res = half;
            hi = half - 1;
        } else{
            lo = half + 1;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("NUMORDER.INP", "r", stdin);
    freopen("NUMORDER.OUT", "w", stdout);
    cin >> n >> m >> k;
    if(n > m) swap(n, m);
    ll res;
    res = numorder();
    cout << res;
    return 0;
}
