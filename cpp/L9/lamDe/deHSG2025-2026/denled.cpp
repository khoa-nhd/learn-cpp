#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[1005][100] = {};
ll n, k, a[1005];

void readData(){
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
}

ll sol(){
    for(int i = 0; i <= n; ++i){
        for(int j = 0; j < k; ++j){
            dp[i][j] = -LLONG_MAX;
        }
    }
    dp[0][0] = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < k; ++j) dp[i][j] = dp[i-1][j];
        for(int j = 0; j < k; ++j){
            if(dp[i-1][j] == -LLONG_MAX) continue;
            ll v = dp[i-1][j] + a[i];
            int r = v % k;
            dp[i][r] = max(dp[i][r], v);
        }
    }
//    for(int i = 1; i <= n; ++i){
//        for(int j = 0; j < k; ++j){
//            cout << dp[i][j] << " ";
//        }
//        cout << "\n";
//    }
    if(dp[n][0] > 0) return dp[n][0];
    return 0;
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
