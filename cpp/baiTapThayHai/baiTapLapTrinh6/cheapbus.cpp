#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll a[15];
pair<ll, ll> dp[1000] = {};

void readData(){
    for(int i = 1; i <= 10; ++i){
        cin >> a[i];
    }
    cin >> n;
}

void cheapbus(){
    for(int i = 0; i < 200; ++i) dp[i].first = LLONG_MAX;
    dp[0].first = 0;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= 10; ++j){
            if(i >= j){
                if(dp[i].first > dp[i-j].first + a[j]){
                    dp[i].first = dp[i-j].first + a[j];
                    dp[i].second = j;
                }
            }
        }
    }

//    for(int i = 0; i <= n; ++i){
//        cout << dp[i].first << " " << dp[i].second << "\n";
//    }
//    cout << "\n";
    vector<ll> res;
    for(int i = n; i > 0; i){
        res.push_back(dp[i].second);
        i -= dp[i].second;
    }
    for(int i = res.size() - 1; i >= 0; --i){
        cout << res[i] << "\n";
    }
    cout << dp[n].first;
}

int main(){
    freopen("CHEAPBUS.INP", "r", stdin);
    freopen("CHEAPBUS.OUT", "w", stdout);
    readData();
    cheapbus();
    return 0;
}
