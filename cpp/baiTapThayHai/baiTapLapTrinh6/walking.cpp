#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;
ll x, y;

ll walking(){
    ll res = 0;
    ll minCanh;
    ll minX, minY;
    minX = min(x-1, n-x);
    minY = min(y-1, m-y);
    minCanh = min(minX, minY) * 2 + 1;
    res = minCanh * minCanh;
    if(x + (minCanh-1)/2 + 1 <= n){
        res += minCanh;
        if(y - ((minCanh-1)/2 + 1) >= 1){
            res += minCanh + 1;
            if(x - ((minCanh-1)/2 + 1) >= 1){
                res += minCanh + 1;
            }
        }
    }
    return res;
}

int main(){
    freopen("WALKING.INP", "r", stdin);
    freopen("WALKING.OUT", "w", stdout);
    cin >> n >> m >> x >> y;
    ll res;
    res = walking();
    cout << res << "\n";
    return 0;
}
