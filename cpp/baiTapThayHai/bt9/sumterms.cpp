#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;

ll sumterm(ll a){
    if(a <= k) return 1;
    ll x = (a + k) / 2;
    ll y = (a - k) / 2;
    if(x + y != a) return 1;
    return sumterm(x) + sumterm(y);
}

int main(){
    freopen("SUMTERMS.INP", "r", stdin);
    freopen("SUMTERMS.OUT", "w", stdout);
    cin >> n >> k;
    ll res;
    res = sumterm(n);
    cout << res;
    return 0;
}
