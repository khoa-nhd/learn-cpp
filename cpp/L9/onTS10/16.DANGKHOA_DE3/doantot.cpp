#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

pair<ll, ll> a[maxN];
ll n;
ll mod = 1e9+7;
bool mot = true;
ll maxr = LLONG_MIN;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
        if(a[i].first != a[i].second) mot = false;
        maxr = max(maxr, a[i].second);
    }
}

void sub1(){
    unordered_map<ll, ll> um;
    for(int i = 0; i < n; ++i){
        ll res = 1;
        um[a[i].first] += 1;
        for(auto x : um){
            res *= x.second;
            res %= mod;
        }
        cout << res << "\n";
    }
}

void sub2(){
    ll dd[1005] = {};
    ll pre[1005] = {};
    for(int i = 0; i < n; ++i){
        dd[a[i].first] += 1;
        dd[a[i].second+1] -= 1;
        for(int j = 1; j <= 1000; ++j){
            pre[j] = pre[j-1] + dd[j];
        }
        ll res = 1;
        ll curr = 0;
        for(int j = 1; j <= 1000; ++j){
            if(pre[j] > 0){
                curr += pre[j];
            } else if(curr != 0){
                res *= curr;
                res %= mod;
                curr = 0;
            }
        }
        cout << res << "\n";
    }
}

void sub3(){
    vector<pair<ll, ll>> v;
    for(int i = 0; i < n; ++i){
        v.push_back({a[i].first, a[i].second});
        sort(v.begin(), v.end());
        ll res = 1;
        ll curr = 1;
        for(int j = 1; j < v.size(); ++j){
            if(v[j].first <= v[j-1].second){
                curr += 1;
            } else if(curr != 1){
                res *= curr;
                res %= mod;
                curr = 1;
            }
        }
        res *= curr;
        res %= mod;
        cout << res << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("DOANTOT.INP", "r", stdin);
    freopen("DOANTOT.OUT", "w", stdout);
    readData();
    if(mot && n <= 1000) sub1();
    else sub3();
    return 0;
}
