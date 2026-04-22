#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[1005], b[1005];
unordered_map<ll, ll> um;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
}

ll bpairs(){
    for(int i = 0; i < n; ++i){
        um[a[i]] += 1;
    }
    ll res = 0;
    for(int i = 0; i < n; ++i){
        if(um[b[i]] > 0){
            res += 1;
            um[b[i]] -= 1;
        }
    }
    if(res < n) return res + 1;
    if(res == n) return res - 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BPAIRS.INP", "r", stdin);
    freopen("BPAIRS.OUT", "w", stdout);
    readData();
    ll res;
    res = bpairs();
    cout << res;
    return 0;
}
