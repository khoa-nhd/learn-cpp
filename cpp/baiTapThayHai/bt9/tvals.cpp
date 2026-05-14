#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, x;
ll a[5005];

void readData(){
    cin >> n >> x;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void tvals(){
//    unordered_map<ll, pair<ll, ll>> um;
    unordered_map<ll, ll> um;
    ll res = 0;
//    for(int i = 0; i < n; ++i){
//        ll target = x - a[i];
//        if(um.find(target) != um.end()){
//            cout << um[target].first+1 << " " << um[target].second+1 << " " << i+1;
//            return;
//        }
//        for(int j = i+1; j < n; ++j){
//            um[a[i]+a[j]] = {i, j};
//        }
//    }
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            ll need = x - a[i] - a[j];
            if(um.find(need) != um.end()){
                cout << i+1 << " " << j+1 << " " << um[need]+1;
                return;
            }
        }
        um[a[i]] = i;
    }
    cout << "IMPOSSIBLE";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TVALS.INP", "r", stdin);
    freopen("TVALS.OUT", "w", stdout);
    readData();
    tvals();
    return 0;
}
