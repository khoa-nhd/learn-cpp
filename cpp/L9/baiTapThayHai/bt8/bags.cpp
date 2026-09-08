#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

ll n, k;
pair<ll, ll> a[maxN];
multiset<ll> ms;

void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
    }
    for(int i = 0; i < k; ++i){
        ll temp;
        cin >> temp;
        ms.insert(temp);
    }
}

bool cmp(pair<ll, ll> x, pair<ll, ll> y){
    if(x.second == y.second) return x.first < y.first;
    return x.second > y.second;
}

ll bags(){
    sort(a, a + n, cmp);
    ll res = 0;
    for(int i = 0; i < n; ++i){
        auto it = ms.lower_bound(a[i].first);
        if(it != ms.end()){
            res += a[i].second;
            ms.erase(it);
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BAGS.INP", "r", stdin);
    freopen("BAGS.OUT", "w", stdout);
    readData();
    ll res;
    res = bags();
    cout << res;
    return 0;
}
