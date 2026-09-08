#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    freopen("UOCCHUNG.INP", "r", stdin);
    freopen("UOCCHUNG.OUT", "w", stdout);
    ll a, b;
    cin >> a >> b;
    ll ucln = __gcd(a, b);
    ll res = -1;
    ll m = sqrt(ucln);
    for(int i = 2; i <= m; ++i){
        if(ucln % i == 0){
            res = ucln / i;
        }
    }
    cout << res;
    return 0;
}
