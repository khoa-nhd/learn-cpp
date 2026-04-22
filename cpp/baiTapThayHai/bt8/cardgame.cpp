#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, a[maxN];
struct cmp{
    bool operator()(pair<ll, ll> a, pair<ll, ll> b){
        if(a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    }
};
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp> pq;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        pq.push({a[i], 0LL});
    }
}

ll cardgame(){
    while(pq.size() > 1){
        pair<ll, ll> t1 = pq.top();
        pq.pop();
        pair<ll, ll> t2 = pq.top();
        pq.pop();
        pq.push({t1.first + t2.first, max(t1.second, t2.second) + 1});
//        cout << t1.first + t2.first << " " << max(t1.second, t2.second) + 1 << "\n";
    }
    return pq.top().second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CARDGAME.INP", "r", stdin);
    freopen("CARDGAME.OUT", "w", stdout);
    readData();
    ll res;
    res = cardgame();
    cout << res;
    return 0;
}
