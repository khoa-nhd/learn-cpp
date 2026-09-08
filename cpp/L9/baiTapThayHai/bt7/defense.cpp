#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

ll n, a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll defense(){
    vector<ll> res;
    for(int i = 0; i < n; ++i){
        if(res.size() == 0 || res.back() < a[i]){
            res.push_back(a[i]);
        } else{
            ll idx = lower_bound(res.begin(), res.end(), a[i]) - res.begin();
            res[idx] = a[i];
        }
    }
    return res.size();
}

int main(){
    ios_base::sync_with_stdio();
    cin.tie(0);
    freopen("DEFENSE.INP", "r", stdin);
    freopen("DEFENSE.OUT", "w", stdout);
    readData();
    ll res;
    res = defense();
    cout << res;
    return 0;
}
