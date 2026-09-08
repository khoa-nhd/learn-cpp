#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m, n;

ll demUoc(ll x){
    ll res = 0;
    for(int i = 2; i * i < x; ++i){
        if(x % i == 0){
            res += i;
            res += x / i;
        }
    }
    ll s = sqrt(x);
    if(s * s == x) res += s;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BAI1.INP", "r", stdin);
    freopen("BAI1.OUT", "w", stdout);
    cin >> m >> n;
    if(demUoc(m) == demUoc(n)) cout << "YES";
    else cout << "NO";
    return 0;
}
