#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, a[maxN] = {};
ll pre[maxN] = {};
ll res = LLONG_MIN;

void readData(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    pre[0] = 0;
    for(int i = 1; i <= n; ++i){
        pre[i] = pre[i-1] + a[i];
    }
}

ll f(ll i, ll j){
    ll l = i;
    ll r = j - 1;
    ll m = -1;
    while(l <= r){
        ll half = (l + r) / 2;
        if(pre[j] - pre[half] == pre[half] - pre[i-1]) m = half;
        if(pre[j] - pre[half] >= pre[half] - pre[i-1]){
            l = half + 1;
        } else{
            r = half - 1;
        }
    }
    if(m == -1) return 0;
    return max(f(i, m), f(m+1, j)) + 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("RELAX.INP", "r", stdin);
    freopen("RELAX.OUT", "w", stdout);
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        readData();
        ll res = f(1, n);
        cout << res << "\n";
    }
    return 0;
}
