#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

ll num(ll x){
    if(x == 0) return 1;
    ll res = 0;
    while(x > 0){
        res += 1;
        x /= 10;
    }
    return res;
}

ll cnt(ll x){
    if(x < 0) return 0;
    ll i = 10;
    ll num = 1;
    ll res = 1;
    while(i <= x){
        res += 9*(i/10)*num;
        num += 1;
        i *= 10;
    }
    i /= 10;
    res += (x-i+1) * num;
    return res;
}

bool segment(ll l){
    ll d = 0, c = 1e17;
    ll r = -1;
    ll vl = cnt(l - 1);
    while(d <= c){
        ll half = (d + c) / 2;
        ll v = cnt(half);
        ll ch = v - vl;
        if(ch == n){
            r = half;
        }
        if(ch > n){
            c = half - 1;
        } else{
            d = half + 1;
        }
    }
    if(r == -1) return false;
    cout << r - l + 1 << "\n";
    cout << l << " " << r;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SEGMENT.INP", "r", stdin);
    freopen("SEGMENT.OUT", "w", stdout);
    cin >> n;
    ll i = 0;
    while(true){
        if(segment(i)) break;
        i += 1;
    }
    return 0;
}
