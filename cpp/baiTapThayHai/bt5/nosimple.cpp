#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull a, b, c;

ull cong(ull x, ull y){
    x %= c;
    y %= c;
    if(x >= c - y) return x - (c - y);
    return x + y;
}

ull nhan(ull x, ull y){
    if(y == 0 || x == 0) return 0;
    ull res = 0;
    ull temp = nhan(x, y/2);
    ull temp2 = cong(temp, temp);
    if(y%2 == 0) return temp2;
    else return cong(x, temp2);
}

ull mu(ull base, ull power){
    if(power == 0) return 1;
    ull temp = mu(base, power/2) % c;
    ull temp2 = nhan(temp, temp);

//    if(power % 2 == 0) cout << "mu: " << temp << "\n";
//    else cout << "mu: " << nhan(base, temp) << "\n";

    if(power % 2 == 0) return temp2;
    else return nhan(base, temp2);
}

int main(){
    freopen("NOSIMPLE.INP", "r", stdin);
    freopen("NOSIMPLE.OUT", "w", stdout);
    cin >> a >> b >> c;
    cout << mu(a, b) % c;
    return 0;
}
