#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    freopen("TAKEABUS.INP", "r", stdin);
    freopen("TAKEABUS.OUT", "w", stdout);
    ll x, a;
    cin >> x >> a;
    ll d = (a / x) * x;
    ll c = (a / x + 1) * x;
    cout << min(a - d, c - a);
    return 0;
}
