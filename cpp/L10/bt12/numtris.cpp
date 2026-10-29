#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 1e9 + 7;
ll n;

ll mu(ll base, ll power){
    if(power == 0) return 1;
    ll temp = mu(base, power/2);
    temp *= temp;
    temp %= mod;
    if(power % 2 == 0) return temp;
    return (temp * base) % mod;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("NUMTRIS.INP", "r", stdin);
    freopen("NUMTRIS.OUT", "w", stdout);
    ll t;
    cin >> t;
    while(t--){
        cin >> n;
        cout << (2*mu(3, n) - 1) % mod << "\n";
    }
    return 0;
}
