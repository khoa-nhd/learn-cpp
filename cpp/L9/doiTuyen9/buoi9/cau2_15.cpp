#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[1005], h;

void readData(){
    cin >> n >> h;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll sol(){
    ll s = a[0];
    ll res = 1;
    for(int i = 1; i < n; ++i){
        if(a[i] - s > h){
            res += 1;
            s = a[i];
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CAU2_15.INP", "r", stdin);
    freopen("CAU2_15.OUT", "w", stdout);
    readData();
    ll res;
    res = sol();
    cout << res;
    return 0;
}
