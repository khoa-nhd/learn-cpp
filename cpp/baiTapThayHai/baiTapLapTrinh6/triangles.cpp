#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[100000];
vector<pair<ll, ll>> v;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll lowerthan(ll target, ll lo){
    ll hi = v.size()-1;
    ll res = -1;
    while(lo <= hi){
        ll half = (lo + hi) / 2;
        if(v[half].first < target){
            res = half;
            lo = half + 1;
        } else hi = half - 1;
    }
    return res;
}

ll greaterthan(ll target, ll lo){
    ll hi = v.size()-1;
    ll res = -1;
    while(lo <= hi){
        ll half = (lo + hi) / 2;
        if(v[half].first > target){
            res = half;
            hi = half - 1;
        } else lo = half + 1;
    }
    return res;
}

ll triangles(){
    map<ll, ll> m;
    ll res = 0;
    for(int i = 0; i < n; ++i){
        m[a[i]] += 1;
    }

    for(auto x : m){
        v.push_back({x.first, x.second});
    }
//    for(auto x : v){
//        cout << x.first << " " << x.second << "\n";
//    }

    for(int i = 0; i < v.size(); ++i){
        for(int j = i+1; j < v.size(); ++j){
            ll mot = lowerthan(v[i].first + v[j].first, j+1);
            ll hai = greaterthan(abs(v[i].first - v[j].first), j+1);
            if(mot == -1 || hai == -1) continue;
            res += abs(mot - hai) + 1;
        }
    }

    for(int i = 0; i < v.size(); ++i){
        if(v[i].second >= 2){
            res += lowerthan(v[i].first * 2, 0);
        }
        if(v[i].second >= 3){
            res += 1;
        }
    }

    return res;
}

int main(){
    freopen("TRIANGLES.INP", "r", stdin);
    freopen("TRIANGLES.OUT", "w", stdout);
    readData();
    ll res;
    res = triangles();
    cout << res;
    return 0;
}
