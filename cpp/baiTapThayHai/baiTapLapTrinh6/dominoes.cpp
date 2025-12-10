#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n;
pair<ll, ll> a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
    }
}

ll dominoes(){
    sort(a, a + n);
    unordered_map<ll, ll> cnt;
    for(int i = 0; i < n; ++i){
        if(cnt.find(a[i].first) != cnt.end()){
            if(cnt.find(a[i].second) != cnt.end()){
                cnt[a[i].second] = max(cnt[a[i].first] + 1, cnt[a[i].second]);
            } else{
                cnt[a[i].second] = cnt[a[i].first] + 1;
            }
        } else{
            if(cnt.find(a[i].second) != cnt.end()){
                cnt[a[i].second] = max(1LL, cnt[a[i].second]);
            } else{
                cnt[a[i].second] = 1;
            }
        }
    }
    ll res = LLONG_MIN;
    for(auto& p : cnt){
        res = max(res, p.second);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("DOMINOES.INP", "r", stdin);
    freopen("DOMINOES.OUT", "w", stdout);
    readData();
    ll res = dominoes();
    cout << res;
    return 0;
}
