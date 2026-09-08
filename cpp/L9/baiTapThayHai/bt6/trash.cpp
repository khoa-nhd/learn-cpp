#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll n, t, a[maxN];
ll pre[maxN] = {};

void readData(){
    cin >> n >> t;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
}

ll trash(){
    for(int i = 1; i <= n; ++i) pre[i] = pre[i-1] + a[i];
    ll res = 0;
    ll r = 1;
    for(int l = 1; l <=n; ++l){
        while((l > r || pre[r+1] - pre[l-1] <= t) && r < n){
            r += 1;
        }
        if(pre[r] - pre[l-1] <= t) res += r - l + 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TRASH.INP", "r", stdin);
    freopen("TRASH.OUT", "w", stdout);
    readData();
    ll res;
    res = trash();
    cout << res;
    return 0;
}
