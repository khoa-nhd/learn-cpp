#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, a[55];
ll dp[255] = {};

void readData(){
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        cin >> a[i];
    }
}

ll coinChange(){
    dp[0] = 1;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j <= n; ++j){
            if(j - a[i] >= 0) dp[j] += dp[j - a[i]];
//            cout << j << " " << dp[j] << "\n";
        }
    }
    return dp[n];
}

int main(){
    freopen("COINCHANGE.INP", "r", stdin);
    freopen("COINCHANGE.OUT", "w", stdout);
    readData();
    ll res;
    res = coinChange();
    cout << res;
    return 0;
}
