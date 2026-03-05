#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m[505];
bool dp[505][200005];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> m[i];
    }
}

void emerald(){
    ll sum = 0;
    for(int i = 0; i < n; ++i){
        sum += m[i];
    }
    if(sum % 3 != 0){
        cout << 0;
        return;
    }
    ll need = sum / 3;
    for(int i = 0; i < n; ++i) dp[i][0] = true;
    for(int i = 0; i < n; ++i){
        for(int j = 1; j <= need; ++j){
            if(i > 0) dp[i][j] = dp[i-1][j];
            if(j - m[i] >= 0 && i > 0) dp[i][j] = dp[i][j] || dp[i-1][j-m[i]];
//            cout << dp[i][j] << " ";
        }
//        cout << "\n";
    }
    if(!dp[n-1][need]){
        cout << 0;
        return;
    }
    ll x = n-1;
    ll y = need;
    vector<ll> res;
    while(y != 0 && x > 0){
        if(dp[x-1][y-m[x]]){
            res.push_back(x);
            y -= m[x];
        }
        x -= 1;
    }
    cout << res.size() << "\n";
    for(ll x : res) cout << x+1 << " ";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("EMERALD.INP", "r", stdin);
    freopen("EMERALD.OUT", "w", stdout);
    readData();
    emerald();
    return 0;
}
