#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, x;

void sol(){
    cin >> a >> b >> x;
    if(a > b) swap(a, b);
    ll res = b - a;
    ll curr = 0;
    while(a != b){
        if(a > b) swap(a, b);
        res = min(res, curr + (b - a));
        if(b - a == 1){
            curr += 1;
            break;
        }
        b /= x;
        curr += 1;
    }
    res = min(res, curr);
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        sol();
    }
    return 0;
}
