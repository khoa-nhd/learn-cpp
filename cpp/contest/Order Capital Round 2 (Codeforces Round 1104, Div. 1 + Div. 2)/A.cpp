#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[105];

void sol(){
    cin >> n;
    ll mi = 1e18;
    ll sum = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        mi = min(mi, a[i]);
        sum += mi;
    }
    cout << sum << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        sol();
    }
    return 0;
}
