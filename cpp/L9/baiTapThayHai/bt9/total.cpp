#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll k;

ll total(){
    ll k2 = 2*k;
    ll res = 0;
    ll m = sqrt(k2);
    for(int i = 1; i <= m; ++i){
        if(k2 % i == 0){
            ll j = k2/i;
            if((j - i + 1) % 2 == 0){
                res += 1;
//                cout << i << "\n";
            }
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TOTAL.INP", "r", stdin);
    freopen("TOTAL.OUT", "w", stdout);
    cin >> k;
    ll res;
    res = total();
    cout << res;
    return 0;
}
