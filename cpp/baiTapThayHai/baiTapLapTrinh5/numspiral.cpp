#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll numspiral(ll x, ll y){
    ll xoanOc = max(x, y);
    ll res;
    if(xoanOc % 2 == 1){
        if(y > x) res = (xoanOc - 1)*(xoanOc - 1) + y + (y - x);
        else res = (xoanOc - 1)*(xoanOc - 1) + y;
    } else{
        if(y > x) res = (xoanOc - 1)*(xoanOc - 1) + x;
        else res = (xoanOc - 1)*(xoanOc - 1) + x + (x - y);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("NUMSPIRAL.INP", "r", stdin);
    freopen("NUMSPIRAL.OUT", "w", stdout);

    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        ll x, y;
        cin >> x >> y;
        ll res = numspiral(x, y);
        cout << res << "\n";
    }
    return 0;
}
