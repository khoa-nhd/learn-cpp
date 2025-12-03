#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;
ll a[55][55] = {};

void readData(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            char temp;
            cin >> temp;
//            cout << temp;
            if(temp == 'X') a[i][j] = -1;
        }
//        cout << "\n";
    }
}

void danh(ll i, ll j, ll so){
    a[i][j] = so;
    if(i + 1 < n && a[i+1][j] == -1) danh(i+1, j, so);
    if(i - 1 < n && a[i-1][j] == -1) danh(i-1, j, so);
    if(j + 1 < m && a[i][j+1] == -1) danh(i, j+1, so);
    if(j - 1 < m && a[i][j-1] == -1) danh(i, j-1, so);
}

ll path(){
    ll so = 1;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(a[i][j] == -1){
                danh(i, j, so);
                so += 1;
            }
        }
    }

    vector<pair<ll, ll>> toaDo1, toaDo2;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(a[i][j] == 1) toaDo1.push_back({i, j});
            if(a[i][j] == 2) toaDo2.push_back({i, j});
        }
    }

//    for(int i = 0; i < n; ++i){
//        for(int j = 0; j < m; ++j){
//            cout << a[i][j];
//        }
//        cout << "\n";
//    }
//
//    for(pair<ll, ll> x : toaDo1){
//        cout << x.first << ", " << x.second << "\n";
//    }
//    cout << "\n";
//    for(pair<ll, ll> x : toaDo1){
//        cout << x.first << ", " << x.second << "\n";
//    }

    ll minDist = LLONG_MAX;
    for(pair<ll, ll> x : toaDo1){
        for(pair<ll, ll> y : toaDo2){
            ll currDist = abs(x.first - y.first) + abs(x.second - y.second) - 1 ;
            minDist = min(minDist, currDist);
        }
    }
    return minDist;
}

int main(){
    freopen("PATH.INP", "r", stdin);
    freopen("PATH.OUT", "w", stdout);
    readData();
    ll res;
    res = path();
    cout << res;
    return 0;
}
