#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

ll m, n;
ll a[maxN][maxN];
pair<ll, ll> cot[maxN][maxN], hang[maxN][maxN];
ll dh[maxN][maxN];
ll ci[] = {-1, 0, 1, 0};
ll cj[] = {0, 1, 0, -1};

void readData(){
    for(int i = 0; i < maxN; ++i){
        for(int j = 0; j < maxN; ++j){
            a[i][j] = LLONG_MIN;
            cot[i][j].first = cot[i][j].second = hang[i][j].first = hang[i][j].second = LLONG_MIN;
        }
    }
    cin >> m >> n;
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }
}

void prep(){
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            cot[i][j].first = max(a[i][j], cot[i-1][j].first);
            hang[i][j].first = max(a[i][j], hang[i][j-1].first);
        }
    }
    for(int i = m; i > 0; --i){
        for(int j = n; j > 0; --j){
            cot[i][j].second = max(a[i][j], cot[i+1][j].second);
            hang[i][j].second = max(a[i][j], hang[i][j+1].second);
        }
    }
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            if(a[i][j] < cot[i][j].first &&
               a[i][j] < cot[i][j].second &&
               a[i][j] < hang[i][j].first &&
               a[i][j] < hang[i][j].second) dh[i][j] = 1;
            else dh[i][j] = 0;
//            cout << dh[i][j] << " ";
        }
//        cout << "\n";
    }
}

bool valid(ll i, ll j){
    return (j <= n && j > 0 && i <= m && i > 0);
}

ll dfs(ll i, ll j){
//    cout << i << " " << j << "\n";
    dh[i][j] = 0;
    ll res = 1;
    for(int k = 0; k < 4; ++k){
        ll x = ci[k] + i;
        ll y = cj[k] + j;
        if(valid(x, y) && dh[x][y] == 1){
            res += dfs(x, y);
        }
    }
    return res;
}

ll bfs(ll i, ll j){
    queue<pair<ll, ll>> q;
    q.push({i, j});
    dh[i][j] = 0;
    ll res = 0;
    while(q.size() > 0){
        pair<ll, ll> toaDo = q.front();
        q.pop();
        res += 1;
        for(int k = 0; k < 4; ++k){
            ll x = toaDo.first + ci[k];
            ll y = toaDo.second + cj[k];
            if(valid(x, y) && dh[x][y] == 1){
                q.push({x, y});
                dh[x][y] = 0;
            }
        }
    }
    return res;
}

ll valley(){
    ll res = 0;
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
//            cout << dh[i][j] << " ";
            if(dh[i][j] == 1){
                res = max(res, bfs(i, j));
//                cout << "\n";
            }
        }
//        cout << "\n";
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("VALLEY.INP", "r", stdin);
    freopen("VALLEY.OUT", "w", stdout);
    readData();
    prep();
    ll res = valley();
    cout << res;
    return 0;
}
