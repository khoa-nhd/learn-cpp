#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m, n, k;

ll th(){
    ll nhom = min(m/2, n);
    ll le = m + n - 3 * nhom;
    k -= le;
    if(k > 0) nhom -= (k+2)/3;
    return nhom;
}

int main(){
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    cin >> m >> n >> k;
    ll res;
    res = th();
    cout << res;
    return 0;
}
