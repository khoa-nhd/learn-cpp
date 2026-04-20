#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;

ll frame(){
    ll a, b;
    ll nn = n;
    if(n % 2 == 1) nn -= 1;
    ll s = nn + 2*m;
    s /= 2;
    a = s / 2;
    b = s - a;
    return a * b;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("FRAME.INP", "r", stdin);
    freopen("FRAME.OUT", "w", stdout);
    cin >> n >> m;
    ll res;
    res = frame();
    cout << res;
    return 0;
}
