#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    ll a, b;
    cin >> a >> b;
    ll bcnn = (a * b) / __gcd(a, b);
    if(a == b){
        cout << 0;
        return 0;
    }
    ll res = bcnn - a - b;
    if(res < 0) res += bcnn;
    cout << res;
    return 0;
}
