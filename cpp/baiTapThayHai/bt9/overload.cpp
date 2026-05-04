#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll a[maxN], b[maxN];
ll n, m;
ll res[maxN];

void readData(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int j = 0; j < m; ++j){
        cin >> b[j];
    }
}

void overload(){
    multiset<pair<ll, ll>> ms;
    for(int i = 0; i < m; ++i){
        ms.insert({b[i], i});
    }
    for(int i = 0; i < n; ++i) res[i] = -1;
    for(int i = n-1; i >= 0; --i){
        auto it = ms.lower_bound({a[i], -1});
        if(it != ms.end()){
            ms.erase(it);
            res[i] = (*it).second+1;
        }
    }
    for(int i = 0; i < n; ++i) cout << res[i] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("OVERLOAD.INP", "r", stdin);
    freopen("OVERLOAD.OUT", "w", stdout);
    readData();
    overload();
    return 0;
}
