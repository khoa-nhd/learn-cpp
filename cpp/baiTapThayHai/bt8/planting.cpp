#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 200005

ll l, a[maxN];
ll n;
multiset<ll> ms;
set<ll> s;

void readData(){
    cin >> l >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void planting(){
    s.insert(0);
    s.insert(l);
    ms.insert(l);
    ll res = LLONG_MIN;
    for(int i = 0; i < n; ++i){
        auto it1 = s.upper_bound(a[i]);
        auto it2 = it1;
        --it2;
        s.insert(a[i]);
        ms.erase(ms.find(*it1 - *it2));
        ms.insert(*it1 - a[i]);
        ms.insert(a[i] - *it2);
        auto it = ms.end();
        --it;
        cout << *it << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PLANTING.INP", "r", stdin);
    freopen("PLANTING.OUT", "w", stdout);
    readData();
    planting();
    return 0;
}
