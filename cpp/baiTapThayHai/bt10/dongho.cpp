#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll h, m;

double dongho(){
    double dh = 0.5 * m + h * 30;
    double dm = 6 * m;
    double res = abs(dh - dm);
    if(res > 180) res = 360 - res;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("DONGHO.INP", "r", stdin);
    freopen("DONGHO.OUT", "w", stdout);
    while(true){
        char c;
        cin >> h >> c >> m;
        if(h == 0 && m == 0) break;
        double res;
        res = dongho();
        cout << fixed << setprecision(3) << res << "\n";
    }
    return 0;
}
