#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;
bool a[40][40] = {};
ll res = LLONG_MAX;
unordered_map<ll, ll> um;

void readData(){
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        ll x, y;
        cin >> x >> y;
        a[x][y] = true;
        a[y][x] = true;
//        cout << x << " " << y << "\n";
    }
}

void nuaDau(ll i, vector<bool> v, ll m){
    if(i == n / 2 + 1){
        ll x = 0;
        for(int i = 1; i < v.size(); ++i){
            x = x << 1;
            if(v[i]) x = x | 1;
//            cout << v[i];
        }
//        cout << "\n";
        auto it = um.find(x);
        if(it != um.end()){
            um[x] = min(um[x], m);
        } else{
            um[x] = m;
        }
        return;
    }
    nuaDau(i+1, v, m);
    for(int j = 0; j <= n; ++j){
        if(a[i][j]){
            v[j] = !v[j];
//            cout << i << " " << j << "\n";
        }
    }
    v[i] = !v[i];
    nuaDau(i+1, v, m + 1);
}

void nuaSau(ll i, vector<bool> v, ll m){
    if(i == n + 1){
        ll x = 0;
        for(int i = 1; i < v.size(); ++i){
            x = x << 1;
            if(!v[i]) x = x | 1;
//            cout << v[i];
        }
//        cout << "\n";
        auto it = um.find(x);
        if(it != um.end()){
            res = min(res, um[x] + m);
        }
        return;
    }
    nuaSau(i+1, v, m);
    bool x;
    for(int j = 0; j <= n; ++j){
        if(a[i][j]){
            v[j] = !v[j];
            x = v[j];
        }
    }
    v[i] = !v[i];
    nuaSau(i+1, v, m + 1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("LIGHTS.INP", "r", stdin);
    freopen("LIGHTS.OUT", "w", stdout);
    readData();
    vector<bool> v;
    for(int i = 0; i <= n; ++i) v.push_back(false);
    nuaDau(1, v, 0);
//    cout << "\n";
    nuaSau(n/2 + 1, v, 0);
    cout << res;
    return 0;
}
