#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

ll tournament(){
    vector<ll> ng;
    for(int i = 1; i <= n; ++i){
        ng.push_back(i);
    }
    n /= 2;
    while(n > 0){
        vector<ll> ngTh;
        for(int i = 0; i < n; ++i){
            ll ngThang;
            cin >> ngThang;
            ngTh.push_back(ng[i*2+ngThang-1]);
        }
        ng = ngTh;
        n /= 2;
    }
    return ng[0];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TOURNAMENT.INP", "r", stdin);
    freopen("TOURNAMENT.OUT", "w", stdout);
    cin >> n;
    ll res;
    res = tournament();
    cout << res;
    return 0;
}
