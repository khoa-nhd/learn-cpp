#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b;

bool check(ll x){
    while(x > 0){
        if(x % 10 == 5) return true;
        x /= 10;
    }
    return false;
}

void test2(){
    ll cnt = 0;
    for(int i = 1; i <= 6574; ++i){
        if(check(i)){
            cnt += 1;
//            cout << i << "\n";
        }
    }
    cout << cnt << "\n";
}

ll sochuso(ll x){
    ll res = 0;
    while(x > 0){
        res += 1;
        x /= 10;
    }
    return res;
}

ll unlucky(ll x){
    ll n = x;
    ll num = sochuso(x);
    ll mul10 = 1;
    x = 0;
    for(int i = 1; i < num; ++i){
        mul10 *= 10;
    }
    for(int i = 0; i < num; ++i){
        if(n / mul10 % 10 == 5){
            mul10 /= 10;
            x *= 10;
            x += 4;
            while(mul10 > 0){
                x *= 10;
                x += 9;
                mul10 /= 10;
            }
            break;
        }
        x *= 10;
        x += n / mul10 % 10;
        mul10 /= 10;
    }
    ll res = 0;
    ll mul9 = 1;
    while(x > 0){
        int v = x % 10;
        if(v >= 5) v -= 1;
        res += mul9*v;
        mul9 *= 9;
        x /= 10;
    }
    return n - res;
}

int main(){
    freopen("UNLUCKY.INP", "r", stdin);
    freopen("UNLUCKY.OUT", "w", stdout);
//    test2();
    cin >> a >> b;
    cout << unlucky(b) - unlucky(a-1);
    return 0;
}
