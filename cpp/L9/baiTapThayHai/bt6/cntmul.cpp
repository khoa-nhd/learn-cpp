#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll l, h, a, b;

ll cntMul(ll n){
    ll hMul = h / n;
    ll lMul = (l - 1) / n;
    return hMul - lMul;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CNTMUL.INP", "r", stdin);
    freopen("CNTMUL.OUT", "w", stdout);
    cin >> l >> h >> a >> b;
    ll bcnn = (a*b) / __gcd(a, b);
    cout << cntMul(a) + cntMul(b) - 2 * cntMul(bcnn);
    return 0;
}
