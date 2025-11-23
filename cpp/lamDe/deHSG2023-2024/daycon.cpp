#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 10005

ll n, k, a[maxN];
ll prefixSum[maxN] = {};

void readData(){
    cin >> n >> k;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
}

ll daycon(){
    for(int i = 1; i <= n; ++i){
        prefixSum[i] = prefixSum[i-1] + a[i];
    }

    ll res = 0;
    ll l = 1;
    ll r = 1;
    for(l; l <= n; ++l){
        while(r <= n){
            ll tong = prefixSum[r] - prefixSum[l-1];
            if(tong >= k){
                res += n - r + 1;
                break;
            }
            r += 1;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("i.INP", "r", stdin);
    freopen("o.OUT", "w", stdout);
    readData();
    ll res;
    res = daycon();
    cout << res;
    return 0;
}

