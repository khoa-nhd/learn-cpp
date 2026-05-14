#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    freopen("HOAHOC.INP", "r", stdin);
    freopen("HOAHOC.OUT", "w", stdout);
    ll a, b;
    cin >> a >> b;
    cout << min(a/3, b/2);
    return 0;
}
