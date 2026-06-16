#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, x, y, z;

ll sol(){
    ll m = (n + x + y - 1) / (x + y);
    ll h = (n - x*z + 10*y + x - 1) / (10*y + x) + z;
    return min(m, h);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        cin >> n >> x >> y >> z;
        ll res;
        res = sol();
        cout << res << "\n";
    }
    return 0;
}
