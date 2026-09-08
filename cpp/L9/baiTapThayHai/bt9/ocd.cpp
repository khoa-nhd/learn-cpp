#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

ll n;

ll getidx(ll x){
    ll res = 0;
    while(x > 0){
        x /= 10;
        res += 1;
    }
    return res - 1;
}

ll get10(ll x){
    ll res = 1;
    while(x > 0){
        res *= 10;
        x /= 10;
    }
    res /= 10;
    return res;
}

ll tang(ll x, ll idx){
    ll ten = get10(x) / 10;
    ll i = 0;
    while(ten > 0 && i < idx){
        ll num = (x / ten) % 10;
        ll prevNum = (x / (ten * 10)) % 10;
        if(num == prevNum){
            x += ten;
            return tang(x, i);
        }
        ten /= 10;
        i += 1;
    }
    return x;
}

void giam(ll x){
    ll ten1 = get10(x);
    ll ten2 = get10(n);
    if(ten1 > ten2){
        cout << x / ten1 % 10;
        bool so = 0;
        x /= 10;
        while(x > 0){
            cout << so;
            so = !so;
            x /= 10;
        }
        return;
    }
    while(ten1 > 0){
        ll numN = n / ten1 % 10;
        ll numX = x / ten1 % 10;
        if(numX > numN){
            cout << numX;
            ten1 /= 10;
            bool so = 0;
            while(ten1 > 0){
                cout << so;
                so = !so;
                ten1 /= 10;
            }
            return;
        }
        cout << numX;
        ten1 /= 10;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("OCD.INP", "r", stdin);
    freopen("OCD.OUT", "w", stdout);
    cin >> n;
    n += 1;
    ll idx = getidx(n);
    ll t = tang(n, idx);
    giam(t);
    return 0;
}
