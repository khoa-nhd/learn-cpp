#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, s;
ll a[50];
vector<ll> v1, v2;

void readData(){
    cin >> n >> s;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void tao(int idx, int e, ll tong, vector<ll> &v){
    if(idx >= e) return;
    v.push_back(tong + a[idx]);
    tao(idx + 1, e, tong, v);
    tao(idx + 1, e, tong + a[idx], v);
}

void sol(){
    v1.push_back(0);
    v2.push_back(0);
    tao(0, n/2, 0, v1);
    tao(n/2, n, 0, v2);
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    ll res = 0;
    for(int i = 0; i < v1.size(); ++i){
        ll x = s - v1[i];
        auto low = lower_bound(v2.begin(), v2.end(), x);
        auto high = upper_bound(v2.begin(), v2.end(), x);
        int cnt = high - low;
        res += cnt;
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SUBSETCOUNT.INP", "r", stdin);
    freopen("SUBSETCOUNT.OUT", "w", stdout);
    readData();
    sol();
    return 0;
}
