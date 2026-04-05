#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    ll n, m;
    cin >> n >> m;
    ll g = __gcd(n, m);
    cout << g << "\n";
    cout << n / g << " " << m / g;
    return 0;
}
