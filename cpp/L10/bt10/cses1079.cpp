#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll m = 1e9 + 7;
ll fact[maxN] = {};
ll invfact[maxN] = {};

ll mu(ll base, ll power){
    if(power == 0) return 1;
    ll temp = mu(base, power / 2);
    temp = temp * temp % m;
    if(power % 2 == 0) return temp;
    else return (temp * base) % m;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    fact[0] = 1;
    for(int i = 1; i < maxN; ++i){
        fact[i] = fact[i-1] * i % m;
    }
    invfact[maxN - 1] = mu(fact[maxN - 1], m - 2);
    for(int i = maxN - 2; i >= 0; --i){
        invfact[i] = invfact[i+1] * (i + 1) % m;
    }
    ll a, b, c;
    ll n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a >> b;
        ll res = fact[a];
        res = res * invfact[b] % m;
        res = res * invfact[a - b] % m;
        cout << res << "\n";
    }
    return 0;
}
