#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SHINE.INP", "r", stdin);
    freopen("SHINE.OUT", "w", stdout);
    ll x1, y1, x2, y2, r;
    cin >> x1 >> y1 >> x2 >> y2 >> r;
    double res;
    double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    double pi = acos(-1.0);
    if(x1 == x2 && y1 == y2) res = pi*r*r;
    else if(d > 2*r) res = 2*pi*r*r;
    else res = 2*pi*r*r - (2*r*r*acos(d/(2*r)) - (d/2)*sqrt(4*r*r - d*d));
    cout << fixed << setprecision(3) << res;
    return 0;
}
