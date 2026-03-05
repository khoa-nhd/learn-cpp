#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll k;

ll sochuso(ll x){
    ll res = 0;
    while(x > 0){
        res += x % 10;
        x /= 10;
    }
    return res;
}

void perfectNum(){
    ll i = 0;
    ll num = 0;
    while(num < k){
       i += 1;
       ll temp = sochuso(i);
       if(temp == 10) num += 1;
    }
    cout << i;
}

int main(){
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    cin >> k;
    perfectNum();
    return 0;
}
