#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m, n, a[1005][1005];
ll x[4] = {0, -1, 0, 1};
ll y[4] = {-1, 0, 1, 0};
ll so[1005][1005] = {};
ll dienTich[100000] = {};

void readData(){
    cin >> m >> n;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }
}

bool valid(ll i, ll j){
    return (i >= 0 && j >= 0 && i < m && j < n);
}

void dfs(ll i, ll j, ll num){
    so[i][j] = num;
    for(int k = 0; k < 4; ++k){
        ll i2 = i + x[k];
        ll j2 = j + y[k];
        if(valid(i2, j2) && a[i2][j2] == 1 && so[i2][j2] == 0){
            dfs(i2, j2, num);
        }
    }
}

ll island(){
    ll num = 1;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(a[i][j] == 1 && so[i][j] == 0){
                dfs(i, j, num);
                num += 1;
            }
        }
    }

//    for(int i = 0; i < m; ++i){
//        for(int j = 0; j < n; ++j){
//            cout << so[i][j] << " ";
//        }
//        cout << "\n";
//    }
//    cout << "\n";

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(so[i][j] != 0) dienTich[so[i][j]] += 1;
        }
    }

//    for(int i = 1; i < 5; ++i){
//        cout << dienTich[i] << " ";
//    }
//    cout << "\n";

    ll res = LLONG_MIN;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(a[i][j] == 0){
                set<ll> noi;
                for(int k = 0; k < 4; ++k){
                    ll i2 = i + x[k];
                    ll j2 = j + y[k];
                    if(valid(i2, j2) && a[i2][j2] == 1){
                        noi.insert(so[i2][j2]);
                    }
                }
                ll val = 0;
                for(ll x : noi){
//                    cout << x << " ";
                    val += dienTich[x];
                }
//                cout << "\n";
                res = max(res, val);
            }
        }
    }
    return res+1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    ll res;
    res = island();
    cout << res;
    return 0;
}
