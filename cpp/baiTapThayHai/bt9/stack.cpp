#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n;
pair<ll, ll> a[maxN];
ll dp[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first;
    }
    for(int i = 0; i < n; ++i){
        cin >> a[i].second;
    }
}

bool cmp(pair<ll, ll> x, pair<ll, ll> y){
    return x.first + x.second < y.first + y.second;
}

ll sol(){
    sort(a, a + n, cmp);
    for(int i = 0; i < maxN; ++i) dp[i] = 1e18;
    dp[0] = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i; j >= 0; --j){
            if(a[i].second >= dp[j]){
                dp[j+1] = min(dp[j+1], a[i].first + dp[j]);
            }
        }
    }
    for(int i = maxN-1; i >= 0; --i){
        if(dp[i] != 1e18) return i;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("STACK.INP", "r", stdin);
    freopen("STACK.OUT", "w", stdout);
    readData();
    ll res;
    res = sol();
    cout << res;
    return 0;
}
