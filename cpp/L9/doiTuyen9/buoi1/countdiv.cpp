#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll countdiv(ll l, ll r, ll a, ll b){
    ll dividedByA = r/a - (l-1)/a;
    ll dividedByB = r/b - (l-1)/b;
    ll bcnn = (a*b)/gcd(a, b);
    ll dividedByAAndB = r/bcnn - (l-1)/bcnn;
    ll result = dividedByA + dividedByB - dividedByAAndB;
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;

    ll l, r, a, b;
    for(int i = 0; i < t; ++i){
        cin >> l >> r >> a >> b;
        ll result;
        result = countdiv(l, r, a, b);
        cout << result << "\n";
    }

    return 0;
}
