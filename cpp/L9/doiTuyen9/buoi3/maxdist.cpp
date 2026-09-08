#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 10005

ll t, n, a[maxN] = {};

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll maxdist(){
    unordered_map<ll, ll> val;
    ll res = LLONG_MIN;
    for(int i = 0; i < n; ++i){
        if(val.find(a[i]) != val.end()){
            res = max(res, i - val[a[i]]);
        } else{
            val[a[i]] = i;
        }
    }
    if(res == LLONG_MIN) return 0;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for(int i = 0; i < t; ++i){
        readData();
        ll res;
        res = maxdist();
        cout << res << "\n";
    }
    return 0;
}
