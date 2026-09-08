#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, a[maxN];
ll m;
ll mingia[1005] = {};

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < 1005; ++i) mingia[i] = LLONG_MAX;
    cin >> m;
    for(int i = 0; i < m; ++i){
        ll b, c;
        cin >> b >> c;
        mingia[b] = min(mingia[b], c);
    }
    for(int i = 1003; i >= 0; --i){
        mingia[i] = min(mingia[i+1], mingia[i]);
    }
}

ll sol(){
    ll res = 0;
    for(int i = 0; i < n; ++i){
        res += mingia[a[i]];
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BAI1.INP", "r", stdin);
    freopen("BAI1.OUT", "w", stdout);
    readData();
    ll res;
    res = sol();
    cout << res;
    return 0;
}
