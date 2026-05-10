#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, k;
ll a[maxN];
ll mod = 1e9 + 7;
ll dp[maxN] = {};

void readData(){
    cin >> n >> k;
    for(int i = 0; i < k; ++i){
        cin >> a[i];
    }
}

ll wood(){
    dp[0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < k; ++j){
            if(i >= a[j]) dp[i] += dp[i-a[j]] % mod;
            dp[i] %= mod;
        }
    }
    return dp[n];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("WOOD.INP", "r", stdin);
    freopen("WOOD.OUT", "w", stdout);
    readData();
    ll res = 0;
    res = wood();
    cout << res;
    return 0;
}
