#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[55] = {};

void tiling(){
    dp[1] = 1;
    dp[2] = 3;
    for(int i = 3; i <= 50; ++i){
        dp[i] = dp[i-1] + 2*dp[i-2];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TILING.INP", "r", stdin);
    freopen("TILING.OUT", "w", stdout);
    tiling();
    ll n;
    while(cin >> n){
        cout << dp[n] << "\n";
    }
    return 0;
}
