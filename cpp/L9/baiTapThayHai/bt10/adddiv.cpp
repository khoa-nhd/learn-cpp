#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    freopen("ADDDIV.INP", "r", stdin);
    freopen("ADDDIV.OUT", "w", stdout);
    ll a, b;
    cin >> a >> b;
    ll bcnn = a*b / __gcd(a, b);
    ll res = bcnn - a - b;
    if(res < 0) res += bcnn;
    cout << res;
    return 0;
}
