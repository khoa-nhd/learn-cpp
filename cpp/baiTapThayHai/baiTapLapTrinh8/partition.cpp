#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll l, n, a[maxN];
priority_queue<ll, vector<ll>, greater<ll>> pq;
ll sum = 0;

void readData(){
    cin >> l >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        sum += a[i];
    }
}

ll sol(){
    for(int i = 0; i < n; ++i){
        pq.push(a[i]);
    }
    if(l - sum > 0) pq.push(l-sum);
    ll res = 0;
    while(pq.size() > 1){
        ll mot = pq.top();
        pq.pop();
        ll hai = pq.top();
        pq.pop();
        res += mot + hai;
        pq.push(mot+hai);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PARTITION.INP", "r", stdin);
    freopen("PARTITION.OUT", "w", stdout);
    readData();
    ll res;
    res = sol();
    cout << res;
    return 0;
}
