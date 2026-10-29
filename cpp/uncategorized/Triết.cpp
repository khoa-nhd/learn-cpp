#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    freopen("i.inp", "r", stdin);
    freopen("o.out", "w", stdout);
    ll a, b;
    cin >> a >> b;
    ll m = (a*b) / __gcd(a, b);
    ll c1 = m - a - b;
    ll c2 = c1 - m;
    ll c3 = c1 + m;
    if(abs(c1) < abs(c2) && abs(c1) < abs(c3)) cout << c1;
    else if((abs(c2) < abs(c1) && abs(c2) < abs(c3))) cout << c2;
    else cout << c3;
    return 0;
}
