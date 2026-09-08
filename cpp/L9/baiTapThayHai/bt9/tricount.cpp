#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 300005

ll n;
pair<ll, ll> a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
    }
}

ll tricount(){
    unordered_map<ll, ll> x, y;
    ll res = 0;
    for(int i = 0; i < n; ++i){
        x[a[i].first] += 1;
        y[a[i].second] += 1;
    }
    for(int i = 0; i < n; ++i){
        res += (x[a[i].first] - 1) * (y[a[i].second] - 1);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TRICOUNT.INP", "r", stdin);
    freopen("TRICOUNT.OUT", "w", stdout);
    readData();
    ll res;
    res = tricount();
    cout << res;
    return 0;
}
