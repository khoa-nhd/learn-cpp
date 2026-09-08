#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x, y, x2, y2;

int main(){
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    cin >> x >> y >> x2 >> y2;
    ll diffx = abs(x - x2);
    ll diffy = abs(y - y2);
    ll res = max(diffx, diffy);
    cout << res;
    return 0;
}
