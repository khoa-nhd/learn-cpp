#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

void sol(){
    ll tru = 1;
    ll lan = 0;
    while(tru * 2 < n) tru *= 2;
    while(n > 2){
        n -= tru;
        while(n <= tru) tru /= 2;
        lan += 1;
    }
    ll res = 0;
    if(n == 1) res = (lan) % 3;
    else res = (1 + lan) % 3;
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("NUMBERA.INP", "r", stdin);
    freopen("NUMBERA.OUT", "w", stdout);
    while(cin >> n){
        sol();
    }
    return 0;
}
