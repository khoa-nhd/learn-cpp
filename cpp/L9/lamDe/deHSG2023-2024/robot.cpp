#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

ll a, b, c, d;
ll n;

ll demSoLan(ll x, ll y){
    ll minLan = LLONG_MAX;
    for(int i = 0; x*i <= n; ++i){
        if((n - x*i) % y == 0){
            minLan = min(minLan, i + (n - x*i)/y);
        }
    }
    if(minLan == LLONG_MAX) return -1;
    return minLan;
}

int main(){
    freopen("i.INP", "r", stdin);
    freopen("o.OUT", "w", stdout);
    cin >> n >> a >> b >> c >> d;
    ll ngang = demSoLan(a, b);
    ll doc = demSoLan(c, d);
    if(ngang == -1 || doc == -1) cout << -1;
    else cout << ngang + doc;
    return 0;
}
