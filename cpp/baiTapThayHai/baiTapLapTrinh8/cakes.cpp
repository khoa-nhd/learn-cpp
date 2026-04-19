#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, t;
pair<ll, ll> a[maxN];
priority_queue<ll> pq;

void readData(){
    cin >> n >> t;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
    }
}

ll cakes(){
    sort(a, a + n);
    ll tconsumed = 0;
    ll res = 0;
    for(int i = 0; i < n; ++i){
        tconsumed += a[i].second;
        pq.push(a[i].second);
        while(pq.size() > 0 && tconsumed + a[i].first > t){
            tconsumed -= pq.top();
            pq.pop();
        }
        res = max(res, (ll)pq.size());
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CAKES.INP", "r", stdin);
    freopen("CAKES.OUT", "w", stdout);
    readData();
    ll res;
    res = cakes();
    cout << res;
    return 0;
}
