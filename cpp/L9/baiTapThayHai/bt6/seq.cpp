#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, n;
ll soMod = 10000;

ll mu(ll base, ll power){
    if(power == 0) return 1;
    if(power == 1) return base % soMod;
    base %= soMod;
    ll temp = mu(base, power/2);
    temp *= temp;
    temp %= soMod;
    if(power % 2 == 0) return temp;
    else return (base*temp) % soMod;
}

ll seq(){
    ll res;
    res = mu(a, mu(2, n-1));
    return res;
}

int main(){
    freopen("SEQ.INP", "r", stdin);
    freopen("SEQ.OUT", "w", stdout);
    cin >> a >> n;
    ll res;
    res = seq();
    cout << res;
    return 0;
}
