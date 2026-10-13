#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    ll x1, y1;
    ll g = exgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    ll a, b, c;
    cin >> a >> b >> c;
    ll g = gcd(abs(a), abs(b));
    c = -c;
    if(c % g != 0){
        cout << -1;
    } else{
        ll x, y;
        ll d = exgcd(abs(a), abs(b), x, y);
        ll nhan = c / g;
        if(a < 0) x *= -1;
        if(b < 0) y *= -1;
        cout << x * nhan << " " << y * nhan;
    }
    return 0;
}
