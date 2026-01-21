#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll l, r;
ll mu10[100] = {};

ll findmax(ll n){
    ll soChuSo = 1;
    ll soSo = 9 * mu10[soChuSo - 1];
    while(n / soChuSo  > soSo){
        n -= soSo * soChuSo;
        soChuSo += 1;
        soSo = 9 * mu10[soChuSo - 1];
    }
    ll so = mu10[soChuSo-1] + (n - 1) / soChuSo;
    if(n % soChuSo != 0) so -= 1;
    return so;
}

ll findmin(ll n){
    ll soChuSo = 1;
    ll soSo = 9 * mu10[soChuSo - 1];
    while(n / soChuSo  > soSo){
        n -= soSo * soChuSo;
        soChuSo += 1;
        soSo = 9 * mu10[soChuSo - 1];
    }
    ll so = mu10[soChuSo-1] + (n - 1) / soChuSo;
    if((n-1) % soChuSo != 0) so += 1;
    return so;
}

int main(){
    freopen("ENCRYPTION.INP", "r", stdin);
    freopen("ENCRYPTION.OUT", "w", stdout);
    cin >> l >> r;

    mu10[0] = 1;
    for(int i = 1; i < 19; ++i){
        mu10[i] = mu10[i-1] * 10;
    }

    ll res = findmax(r) - findmin(l) + 1;
    res = max(0LL, res);
    cout << res;

    return 0;
}
