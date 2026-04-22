#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[1005];
ll dp[1005] = {};

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll award(){
    for(int i = 0; i < n; ++i) dp[i] = a[i];
    for(int i = 1; i < n; ++i){
        for(int j = i - 1; j >= 0; --j){
            if(a[i] > a[j]){
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
    }
    ll res = 0;
    for(int i = 0; i < n; ++i){
        res = max(res, dp[i]);
//        cout << dp[i] << " ";
    }
//    cout << "\n";
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("AWARD.INP", "r", stdin);
    freopen("AWARD.OUT", "w", stdout);
    readData();
    ll res;
    res = award();
    cout << res;
    return 0;
}
