#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 2005

ll a[maxN][maxN] = {};
ll n, m;
ll ci[] = {-1, 0, 1, 0};
ll cj[] = {0, 1, 0, -1};
ll v[maxN][maxN] = {};
unordered_map<ll, ll> um;

void readData(){
    cin >> m >> n;
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }
}

ll teamseas(){
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            v[i][j] = a[i][j];
            for(int k = 0; k < 4; ++k){
                ll x = i + ci[k];
                ll y = j + cj[k];
                v[i][j] += a[x][y];
            }
        }
    }
    ll maxx = LLONG_MIN;
    ll res = -1;
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
//            cout << v[i][j] << " ";
            um[v[i][j]] += 1;
            if(maxx < um[v[i][j]]){
                maxx = um[v[i][j]];
                res = v[i][j];
            } else if(maxx == um[v[i][j]]){
                res = max(res, v[i][j]);
            }
        }
//        cout << "\n";
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
    res = teamseas();
    cout << res;
    return 0;
}
