#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, c, l, r;

ll mod(){
    ll res = 0;
    ll loop = sqrt(a - c);
    vector<ll> uoc;
    for(int i = 1; i < loop; ++i){
        if((a-c) % i == 0){
            uoc.push_back(i);
            uoc.push_back((a-c)/i);
        }
    }
    if(loop * loop == a - c) uoc.push_back(loop);
    for(int i = 0; i < uoc.size(); ++i){
        if(uoc[i] >= l && uoc[i] <= r && uoc[i] > c) res += 1;
    }
    return res;
}

int main(){
    freopen("MOD.INP", "r", stdin);
    freopen("MOD.OUT", "w", stdout);
    cin >> a >> c >> l >> r;
    ll res;
    res = mod();
    cout << res;
    return 0;
}
