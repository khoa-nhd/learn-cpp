#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m, n, k;
ll a, b;

void maximize(ll &change, ll maxx, ll rem){
    ll d = change;
    ll c = k-rem;
    while(d <= c){
        ll half = (d+c)/2;
        if(half <= maxx){
            change = half;
            d = half + 1;
        } else{
            c = half - 1;
        }
    }
}

ll cut(){
    a = k/2;
    b = (k+1)/2;
    if(a > m) a = m;
    if(b > n) b = n;
    if(a < m && a+b < k){
        maximize(a, m, b);
    }
    if(b < n && a+b < k){
       maximize(b, n, a);
    }
    return (a+1)*(b+1);
}

int main(){
    freopen("CUT.INP", "r", stdin);
    freopen("CUT.OUT", "w", stdout);
    cin >> m >> n >> k;
    m -= 1;
    n -= 1;
    ll res;
    res = cut();
    cout << res;
    return 0;
}
