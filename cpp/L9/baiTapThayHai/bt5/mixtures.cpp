#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[105];

void readData(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
}

ll mixtures(){
    vector<ll> preSum(n+1, 0);
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, LLONG_MAX));
    for(int i = 1; i <= n; ++i){
        preSum[i] = preSum[i-1] + a[i];
    }

    for(int i = 0; i <= n; ++i){
        dp[i][i] = 0;
    }

    for(int i = n; i > 0; --i){
        for(int j = i; j <= n; ++j){
            for(int k = i; k < j; ++k){
                ll color1 = (preSum[k] - preSum[i-1]) % 100;
                ll color2 = (preSum[j] - preSum[k]) % 100;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + color1 * color2);
            }
        }
    }

    return dp[1][n];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MIXTURES.INP", "r", stdin);
    freopen("MIXTURES.OUT", "w", stdout);
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        readData();
        ll res;
        res = mixtures();
        cout << res << "\n";
    }
    return 0;
}
