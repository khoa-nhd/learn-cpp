#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 200005

ll n;
struct khach{
    ll s, e, idx;
} a[maxN];
ll ans[maxN];
struct cmp2{
    bool operator()(pair<ll, ll> a, pair<ll, ll> b){
        return a.first > b.first;
    }
};
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp2> pq;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].s >> a[i].e;
        a[i].idx = i;
    }
}

bool cmp(khach x, khach y){
    if(x.s == y.s) return x.e < y.e;
    return x.s < y.s;
}

void roomsalloc(){
    sort(a, a + n, cmp);
    ll res = LLONG_MIN;
    for(int i = 0; i < n; ++i){
        if(pq.size() == 0){
            pq.push({a[i].e, 1});
            ans[a[i].idx] = 1;
        } else{
            if(a[i].s > pq.top().first){
                pair<ll, ll> t = pq.top();
                pq.pop();
                pq.push({a[i].e, t.second});
                ans[a[i].idx] = t.second;
            } else{
                pq.push({a[i].e, pq.size() + 1});
                ans[a[i].idx] = pq.size();
            }
        }
        res = max(res, (ll)pq.size());
    }
    cout << res << "\n";
    for(int i = 0; i < n; ++i){
        cout << ans[i] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ROOMSALLOC.INP", "r", stdin);
    freopen("ROOMSALLOC.OUT", "w", stdout);
    readData();
    roomsalloc();
    return 0;
}
