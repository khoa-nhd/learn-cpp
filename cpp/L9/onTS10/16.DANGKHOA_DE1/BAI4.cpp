#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

ll n, m;
ll dp[maxN][maxN] = {};

void readData(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> dp[i][j];
        }
    }
}

ll sol(){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(dp[i][j] && dp[i][j-1] && dp[i-1][j-1] && dp[i-1][j]){
                dp[i][j] = min(dp[i][j-1], dp[i-1][j-1]);
                dp[i][j] = min(dp[i][j], dp[i-1][j]);
                dp[i][j] += 1;
            }
        }
    }
    ll res = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            res = max(res, dp[i][j]);
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BAI4.INP", "r", stdin);
    freopen("BAI4.OUT", "w", stdout);
    readData();
    ll res;
    res = sol();
    cout << res;
    return 0;
}
