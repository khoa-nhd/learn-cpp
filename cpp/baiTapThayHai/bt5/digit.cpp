#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ull a, b, k;

ull nhan(ull x, ull y){
    if(y == 0) return 0;
    if(y % 2 == 0) return (2*nhan(x, y/2)) % b;
    else return (nhan(x, y-1) + x) % b;
}

ull mu(ull base, ull power){
    if(power == 0) return 1;
    ull temp = mu(base, power/2) % b;
    ull temp2 = nhan(temp, temp);
    if(power % 2 == 0) return temp2;
    else return nhan(temp2, base);
}

int digit(){
    ll tuSo = nhan(a%b, mu(10, k-1));
    double phanSo = (double)tuSo / (double)b;
    phanSo *= 10;
    return (ll)phanSo % 10;
}

int main(){
    freopen("DIGIT.INP", "r", stdin);
    freopen("DIGIT.OUT", "w", stdout);
    cin >> a >> b >> k;
    int res;
    res = digit();
    cout << res;
    return 0;
}
