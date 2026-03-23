#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

priority_queue<int, vector<int>, greater<int>> pq;
ll n;
pair<ll, ll> a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
    }
}

ll sol(){
    sort(a, a + n);
    for(int i = 0; i < n; ++i){
        if(pq.size() == 0 || pq.top() > a[i].second){
            pq.push(a[i].second);
        } else{
            pq.pop();
            pq.push(a[i].second);
        }
    }
    return pq.size();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BOARD.INP", "r", stdin);
    freopen("BOARD.OUT", "w", stdout);
    readData();
    ll res;
    res = sol();
    cout << res;
    return 0;
}
