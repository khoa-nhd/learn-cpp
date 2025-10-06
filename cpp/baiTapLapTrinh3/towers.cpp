#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

ll n, a[maxN];
multiset<ll> thap;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll tower(){
    ll result = 0;
    for(int i = 0; i < n; ++i){
        auto it = thap.upper_bound(a[i]);
        if(it != thap.end()){
            thap.erase(it);
        }
        thap.insert(a[i]);
    }
    result = thap.size();
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TOWERS.INP", "r", stdin);
    freopen("TOWERS.OUT", "w", stdout);
    readData();
    ll m = tower();
    cout << m;
    return 0;
}
