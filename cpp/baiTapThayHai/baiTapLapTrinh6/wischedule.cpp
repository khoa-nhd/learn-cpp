#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct khach{
    ll a, b, c;
} k[30005];
ll dp[10000000] = {};
ll n;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> k[i].a >> k[i].b >> k[i].c;
    }
}

bool cmp(khach x, khach y){
    if(x.b == y.b) return x.a < y.a;
    return x.b < y.b;
}

ll wischedule(){
    sort(k, k+n, cmp);
    ll idx = 0;
    for(int td = 1; td <= 8640000 && idx < n; ++td){
        dp[td] = dp[td-1];
        while(k[idx].b == td){
            dp[td] = max(dp[td], dp[k[idx].a] + k[idx].c);
            idx += 1;
            if(idx >= n) break;
        }
    }
    return dp[k[n-1].b];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("WISCHEDULE.INP", "r", stdin);
    freopen("WISCHEDULE.OUT", "w", stdout);
    readData();
    ll res;
    res = wischedule();
    cout << res;
    return 0;
}
