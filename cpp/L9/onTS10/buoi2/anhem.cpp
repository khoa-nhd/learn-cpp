#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b;

int tongUoc(ll x){
    ll res = 0;
    for(int i = 2; i * i <= x; ++i){
        if(i * i == x){
            res += i;
            continue;
        }
        if(x % i == 0){
            res += i;
            res += x / i;
        }
    }
    return res;
}

int main(){
    cin >> a >> b;
    if(tongUoc(a) == tongUoc(b)) cout << "YES";
    else cout << "NO";
    return 0;
}
