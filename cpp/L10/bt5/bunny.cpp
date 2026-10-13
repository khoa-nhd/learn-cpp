#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

void sol(){
    n -= 1;
    ll mod = 1000000;
    ll res = 0;
    ll k = n / 6 + 1;
    k %= mod;
    ll s = 3 * k * k - 2 * k;
    res = s + (n % 6) * k;
    if(n % 6 == 5) res += 1;
    res %= mod;
    cout << res << "\n";
}

void test(){
    for(int i = 1; i <= 100; ++i){
        ll t = 0;
        for(int j = 0; j <= i; ++j){
            for(int k = 0; k <= i; ++k){
                for(int z = 0; z <= i; ++z){
                    if(3*j + 2*k + z == i) t += 1;
                }
            }
        }
        cout << t << " ";
        n = i;
        sol();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BUNNY.INP", "r", stdin);
    freopen("BUNNY.OUT", "w", stdout);
    cin >> n;
    sol();
//    test();
    return 0;
}
