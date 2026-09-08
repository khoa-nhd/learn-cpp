#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m, n, k, a[505][505];
ll dp[505][505][205] = {};

void readData(){
    cin >> m >> n >> k;
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }
}

ll sol(){
    for(int i = 0; i <= m; ++i){
        for(int j = 0; j <= n; ++j){
            for(int r = 0; r <= k; ++r){
                dp[i][j][r] = -1;
            }
        }
    }
    dp[1][1][a[1][1] % k] = a[1][1];
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            for(int r = 0; r < k; ++r){
                ll v;
                if(dp[i-1][j][r] != -1){
                    v = dp[i-1][j][r] + a[i][j];
                    dp[i][j][v%k] = max(dp[i][j][v%k], v);
                }
                if(dp[i][j-1][r] != -1){
                    v = dp[i][j-1][r] + a[i][j];
                    dp[i][j][v%k] = max(dp[i][j][v%k], v);
                }
            }
        }
    }
    return dp[m][n][0];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    ll res;
    res = sol();
    cout << res;
    return 0;
}
