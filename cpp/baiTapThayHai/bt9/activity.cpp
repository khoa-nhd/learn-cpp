#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m, n, k, a, b;

ll activity(){
    ll nhomm = m / a;
    ll nhomn = n / b;
    ll minnhom = min(nhomm, nhomn);
    k -= m - minnhom*a;
    k -= n - minnhom*b;
    if(k > 0){
        minnhom -= ((k+a+b-1) / (a+b));
    }
    return minnhom;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ACTIVITY.INP", "r", stdin);
    freopen("ACTIVITY.OUT", "w", stdout);
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        cin >> m >> n >> k >> a >> b;
        ll res;
        res = activity();
        cout << res << "\n";
    }
    return 0;
}
