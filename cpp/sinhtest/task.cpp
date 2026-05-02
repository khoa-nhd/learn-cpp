#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 200005

ll n, s;
ll a[maxN];
ll pre[maxN] = {};
vector<ll> v;

void readData(){
    cin >> n >> s;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
}

ll sol(){
    for(int i = 1; i <= n; ++i){
        pre[i] = pre[i-1] + a[i];
    }
    ll res = LLONG_MIN;
    v.push_back(0);
    for(int i = 1; i <= n; ++i){
        if(pre[i] > pre[v.back()]) v.push_back(i);
    }
    for(int i = n; i > 0; --i){
        while(v.size() > 0 && pre[i] - pre[v.back()] <= s){
            res = max(res, i - v.back());
            v.pop_back();
        }
    }
    if(res <= 0) return -1;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("i.INP", "r", stdin);
    freopen("o.OUT", "w", stdout);
    readData();
    ll res;
    res = sol();
    cout << res;
    return 0;
}
