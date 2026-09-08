#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll p[100], n;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> p[i];
    }
}

ll mu(ll base, ll power){
    ll res = 1;
    for(int i = 0; i < power; ++i){
        res *= base;
    }
    return res;
}

ll luythua(){
    ll res = 0;
    for(int i = 0; i < n; ++i){
        res += mu(p[i]/10, p[i]%10);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    ll res;
    res = luythua();
    cout << res;
    return 0;
}
