#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005
#define maxN2 10000005

ll n;
pair<ll, ll> a[maxN];
ll cot[maxN2] = {};

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
    }
}

ll covering(){
    for(int i = 0; i < n; ++i){
        ll c = a[i].first / 2;
        ll h = a[i].second / 2;
        cot[c] = max(cot[c], h);
    }
    for(int i = maxN2 - 10; i > 0; --i){
        cot[i] = max(cot[i], cot[i+1]);
    }
    ll res = 0;
    for(int i = 1; i < maxN2; ++i){
        res += cot[i];
    }
    return res*4;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("COVERING.INP", "r", stdin);
    freopen("COVERING.OUT", "w", stdout);
    readData();
    ll res;
    res = covering();
    cout << res;
    return 0;
}
