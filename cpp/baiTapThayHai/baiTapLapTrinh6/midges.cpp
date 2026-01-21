#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, a[maxN];
map<ll, ll> cnt;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll midges(){
    ll diChuyen = 0;
    ll res = 0;
    vector<pair<ll, ll>> v;
    for(int i = 0; i < n; ++i){
        cnt[a[i]] += 1;
    }
    for(auto x : cnt){
        v.push_back({x.first, x.second});
    }
    for(int i = v.size()-1; i >= 0; --i){
        if(v[i].first - diChuyen <= 0) continue;
        res += (v[i].first - diChuyen) * v[i].second;
        diChuyen += v[i].second;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MIDGES.INP", "r", stdin);
    freopen("MIDGES.OUT", "w", stdout);
    readData();
    ll res;
    res = midges();
    cout << res;
    return 0;
}
