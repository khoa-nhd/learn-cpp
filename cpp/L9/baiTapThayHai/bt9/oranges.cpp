#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll k;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ORANGES.INP", "r", stdin);
    freopen("ORANGES.OUT", "w", stdout);
    cin >> k;
    ll d = 2;
    ll c = k + 1;
    ll res = ((d + c) * k) / 2;
    cout << res;
    return 0;
}
