#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("AREATRI.INP", "r", stdin);
    freopen("AREATRI.OUT", "w", stdout);
    ll a, h;
    cin >> a >> h;
    if(2*h > a) cout << -1;
    else{
        double res = ((double)a * h) / 2.0;
        cout << fixed << setprecision(1) << res;
    }
    return 0;
}
