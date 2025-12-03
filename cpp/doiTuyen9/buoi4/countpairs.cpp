#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t;

ll countPairs(){
    ll res = 0;
    ll n, a[10005] = {};
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            if(i*a[i] > j*a[j]){
                res += 1;
            }
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    cin >> t;
    for(int i = 0; i < t; ++i){
        ll res;
        res = countPairs();
        cout << res << "\n";
    }
    return 0;
}
