#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, a[maxN] = {};
ll prefixMax[maxN] = {};

ll buildings(){
    ll res = 1;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    prefixMax[0] = a[0];
    for(int i = 1; i < n; ++i){
        prefixMax[i] = max(prefixMax[i-1], a[i]);
    }

    for(int i = 1; i < n; ++i){
        if(a[i] >= prefixMax[i-1]) res += 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        ll res;
        res = buildings();
        cout << res << "\n";
    }
    return 0;
}
