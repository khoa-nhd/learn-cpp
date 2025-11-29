#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, k;

ll mu(ll base, ll power){
    if(power == 0) return 1;
    ll temp = mu(base, power/2) % b;
    if(power % 2 == 0) return (temp * temp) % b;
    else return (((temp * temp) % b) * (base % b)) % b;
}

ll digit(){
    ll tuSo = ((a % b) * mu(10, k)) % b;
    double phanSo = (double)tuSo / (double)b;
    phanSo *= 10;
    return (ll)phanSo % 10;
}

int main(){
    freopen("DIGIT.INP", "r", stdin);
    freopen("DIGIT.OUT", "w", stdout);
    cin >> a >> b >> k;
    ll res;
    res = digit();
    cout << res;
    return 0;
}
