#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x, y, n;

int main(){
    freopen("STAIRS.INP", "r", stdin);
    freopen("STAIRS.OUT", "w", stdout);
    cin >> x >> y >> n;
    ll res = (n + (x + y) - 1) / (x + y);
    ll s = res * (x + y);
    if(s - x >= n){
        res *= 2;
        res -= 1;
    } else res *= 2;
    cout << res;
    return 0;
}
