#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n;
pair<ll, ll> a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
    }
}

void sol(){
    set<pair<ll, ll>> v;
    for(int i = 0; i < n; ++i){
        if(v.size() == 0 && i == 0){
            v.insert(a[i]);
            continue;
        }
        set<pair<ll, ll>> nv;
        for(pair<ll, ll> x : v){
//            cout << x.first << " " << x.second << "\n";
            if(x.first == a[i].first){
                nv.insert({x.first, x.second + a[i].second});
            }
            if(x.second == a[i].second){
                nv.insert({x.first + a[i].first, x.second});
            }
            swap(x.first, x.second);
            if(x.first == a[i].first){
                nv.insert({x.first, x.second + a[i].second});
            }
            if(x.second == a[i].second){
                nv.insert({x.first + a[i].first, x.second});
            }
        }
        v = nv;
    }
    set<pair<ll, ll>> res;
    for(pair<ll, ll> x : v){
        res.insert({min(x.first, x.second), max(x.first, x.second)});
    }
    cout << res.size() << "\n";
    for(pair<ll, ll> x : res){
        cout << x.first << " " << x.second << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("FAIR.INP", "r", stdin);
    freopen("FAIR.OUT", "w", stdout);
    readData();
    sol();
    return 0;
}
