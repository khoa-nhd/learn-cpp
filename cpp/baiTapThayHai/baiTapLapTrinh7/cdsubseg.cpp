#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll n, a[maxN];
ll d[maxN] = {};

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if(a[i] < 0) a[i] = -a[i];
    }
}

ll cdsubseg(){
    vector<pair<ll, ll>> curr;
    ll res = 0;
    if(a[0] != 1){
        curr.push_back({a[0], 1});
        res = max(res, 1LL);
    }
    for(int i = 1; i < n; ++i){
        vector<pair<ll, ll>> neww;
        if(a[i] != 1){
            res = max(res, 1LL);
            neww.push_back({a[i], 1});
        }
        for(int j = 0; j < curr.size(); ++j){
            ll g = __gcd(curr[j].first, a[i]);
            if(g != 1){
                neww.push_back({g, curr[j].second+1});
                res = max(curr[j].second+1, res);
            }
        }
        curr.clear();
        sort(neww.begin(), neww.end());
        for(int i = 0; i < neww.size(); ++i){
            if(i == neww.size() - 1 || neww[i].first != neww[i+1].first){
                curr.push_back({neww[i].first, neww[i].second});
            }
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CDSUBSEG.INP", "r", stdin);
    freopen("CDSUBSEG.OUT", "w", stdout);
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        readData();
        ll res;
        res = cdsubseg();
        cout << res << "\n";
    }
    return 0;
}
