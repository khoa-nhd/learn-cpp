#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m = 1e9 + 7;

ll mu(ll base, ll power){
    if(power == 0) return 1;
    ll temp = mu(base, power / 2);
    temp *= temp;
    temp %= m;
    if(power % 2 == 0) return temp;
    else return (temp * base) % m;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    ll a, b;
    ll n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a >> b;
        a %= m;
        b %= m;
        cout << mu(a, b) << "\n";
    }
    return 0;
}
