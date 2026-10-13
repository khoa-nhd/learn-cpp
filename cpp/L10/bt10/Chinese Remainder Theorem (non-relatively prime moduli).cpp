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

bool nhap(long long &a1, long long &m1, long long a2, long long m2) {
    long long p, q;
    long long g = exgcd(m1, m2, p, q);
    if ((a2 - a1) % g != 0) return false;
    long long l = m1 / g * m2;
    ll t = ((a2 - a1) / g) * p % (m2 / g);
    ll x = a1 + m1 * t;
    a1 = (long long)((x % l + l) % l);
    m1 = l;
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        ll m, n;
        ll a, b;
        cin >> a >> n >> b >> m;
        if (nhap(a, n, b, m)) {
            cout << a << ' ' << n << '\n';
        } else {
            cout << "no solution\n";
        }
    }
    return 0;
}
