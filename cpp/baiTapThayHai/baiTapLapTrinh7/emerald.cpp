#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m[505];
bool dp[505][1005];

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
            dp[i][j] = dp[i-1][j];
            if(j - m[i] >= 0) dp[i][j] = dp[i][j] || dp[i-1][j-m[i]];
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    if(!dp[n-1][need]){
        cout << 0;
        return;
    }
    ll i = n-1;
    ll j = need;
    vector<ll> res;
    while(j != 0){
        if(dp[i-1][j-m[i]]){
            res.push_back(i);
            j -= m[i];
        }
        i -= 1;
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
