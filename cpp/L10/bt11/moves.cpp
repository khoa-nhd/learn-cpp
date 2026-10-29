#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;
ll mod = 1e9 + 7;

ll muMod(ll base, ll power){
    if(power == 0) return 1;
    ll temp = muMod(base, power/2);
    temp *= temp;
    temp %= mod;
    if(power%2 == 0) return temp;
    return (base * temp) % mod;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MOVES.INP", "r", stdin);
    freopen("MOVES.OUT", "w", stdout);
    cin >> n >> k;
    cout << muMod(2, n) - 1 << "\n";
    cout << muMod(2, n - k);
    return 0;
}
