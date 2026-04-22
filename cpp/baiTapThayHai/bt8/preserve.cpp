#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 200005

ll n, k, a[maxN];

void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll preserve(){
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    sort(a, a + n);
    for(int i = 0; i < n; ++i){
        if(pq.size() == 0 || a[i] - pq.top() <= k){
            pq.push(a[i]);
        } else{
            pq.pop();
            pq.push(a[i]);
        }
    }
    return pq.size();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PRESERVE.INP", "r", stdin);
    freopen("PRESERVE.OUT", "w", stdout);
    readData();
    ll res;
    res = preserve();
    cout << res;
    return 0;
}
