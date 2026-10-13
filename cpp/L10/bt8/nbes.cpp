#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, a[maxN];
ll k;

void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void solve(){
    sort(a, a + n, greater<int>());
    vector<ll> res;
    priority_queue<pair<ll, ll>> pq;
    for(int i = 0; i < n; ++i){
        if(pq.size() > 0){
            if(a[i] + k <= pq.top().first){
                if(pq.top().second) res.push_back(pq.top().first);
                pq.pop();
                pq.push({a[i], 0});
            } else{
                pq.push({a[i], 1});
            }
        } else{
            pq.push({a[i], 1});
        }
    }
    while(pq.size() > 0){
        if(pq.top().second) res.push_back(pq.top().first);
        pq.pop();
    }
    ll ans = 0;
    for(ll x : res) ans += x;
//    for(ll x : res) cout << x << " ";
//    cout << "\n";
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("NBES.INP", "r", stdin);
    freopen("NBES.OUT", "w", stdout);
    readData();
    solve();
    return 0;
}
