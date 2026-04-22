#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, h;

int main(){
    freopen("AREATRI.INP", "r", stdin);
    freopen("AREATRI.OUT", "w", stdout);
    cin >> a >> h;
    if(h*2 > a) cout << -1;
    else{
        double res = (double)a * (double)h / (double)2;
        cout << fixed << setprecision(1) << res;
    }
    return 0;
}
