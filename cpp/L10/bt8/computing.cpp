#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 200005

ll n, k, a[maxN];
ll sum = 0;
ll pre[maxN] = {};

void readData(){
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        sum += a[i];
    }
}

void solve(){
    for(int i = 1; i <= n; ++i){
        pre[i] = pre[i-1] + a[i];
    }
    ll res = 0;
    for(int i = 1; i <= n; ++i){
        ll d = min(n, i + k) - max(0LL, i - k - 1);
        ll t = sum - (pre[min(n, i + k)] - pre[max(0LL, i - k - 1)]) + a[i] * d;
        res = max(res, t);
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("COMPUTING.INP", "r", stdin);
    freopen("COMPUTING.OUT", "w", stdout);
    readData();
    solve();
    return 0;
}
