#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

ll n, m, a[maxN][maxN];
ll ci[] = {-1, 0, 1, 0};
ll cj[] = {0, 1, 0, -1};

void readData(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> a[i][j];
        }
    }
}

bool valid(ll i, ll j){
    return (i >= 0 && j >= 0 && i < n && j < m);
}

void dfs(ll i, ll j){
    a[i][j] = 0;
    for(int k = 0; k < 4; ++k){
        ll x = i + ci[k];
        ll y = j + cj[k];
        if(valid(x, y) && a[x][y]) dfs(x, y);
    }
}

ll hcn(){
    ll res = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(a[i][j]){
                dfs(i, j);
                res += 1;
            }
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    ll res;
    res = hcn();
    cout << res;
    return 0;
}
