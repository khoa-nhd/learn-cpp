#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;

ll tqueen(){
    ll a = min(m, n);
    ll res = 0;
    res += m + n - 2;
    if(a % 2 == 0){
        if(max(m, n) > a){
            res += 2 * (a - 1);
        } else{
            res += a - 1;
            res += a - 2;
        }
    } else{
        res += 2 * (a - 1);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TQUEEN.INP", "r", stdin);
    freopen("TQUEEN.OUT", "w", stdout);
    cin >> n >> m;
    ll res;
    res = tqueen();
    cout << res;
    return 0;
}
