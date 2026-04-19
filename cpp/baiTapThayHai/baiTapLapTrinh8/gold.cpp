#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, s, a[1005];
ll dp[50005] = {};

void readData(){
    cin >> n >> s;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void gold(){
    dp[0] = 1;
    for(int i = 0; i < n; ++i){
        for(int j = s; j > 0; --j){
            if(j - a[i] >= 0) dp[j] += dp[j-a[i]];
        }
    }
    for(int i = s; i >= 0; --i){
        if(dp[i]){
            cout << i << "\n";
            cout << dp[i] % (ll)(1e9 + 7);
            return;
        }
    }
    cout << 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("GOLD.INP", "r", stdin);
    freopen("GOLD.OUT", "w", stdout);
    readData();
    gold();
    return 0;
}
