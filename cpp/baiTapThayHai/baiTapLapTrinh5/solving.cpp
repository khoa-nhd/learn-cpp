#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, c;

ll mu(ll coSo, ll soMu){
    if(soMu == 0) return 1;
    ll res = coSo;
    for(int i = 1; i < soMu; ++i){
        res *= coSo;
    }
    return res;
}

ll sumNum(ll n){
    ll res = 0;
    while(n > 0){
        res += n % 10;
        n /= 10;
    }
    return res;
}

void solving(){
    for(int i = 1; i <= 72; ++i){
        ll x;
        x = mu(i, a) * b + c;
        if(sumNum(x) == i && x <= 1e9){
            cout << x << "\n";
        }
    }
}

int main(){
    freopen("SOLVING.INP", "r", stdin);
    freopen("SOLVING.OUT", "w", stdout);
    cin >> a >> b >> c;
    solving();
    return 0;
}
