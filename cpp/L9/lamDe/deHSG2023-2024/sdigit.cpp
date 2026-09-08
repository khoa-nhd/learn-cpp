#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

bool prime[maxN] = {};
ll l, r;
ll minn, maxx;

void sangNguyenTo(){
    for(ll i = 2; i < maxN; ++i) prime[i] = true;
    for(ll i = 2; i < maxN; ++i){
        if(prime[i]){
            for(ll j = i * i; j < maxN; j += i){
                prime[j] = false;
            }
        }
    }
}

void calMinMax(){
    minn = 1;
    maxx = 1;
    for(int i = 1; i < l; ++i){
        minn *= 10;
    }
    for(int i = 0; i < r; ++i){
        maxx *= 10;
    }
}

ll sumNum(ll n){
    ll res = 0;
    while(n > 0){
        res += n%10;
        n /= 10;
    }
    return res;
}

ll sdigit(){
    ll res = 0;
    for(int i = minn; i < maxx; ++i){
//        cout << i << " " << sumNum(i) << "\n";
        if(prime[sumNum(i)]) res += 1;
    }
    return res;
}

int main(){
    freopen("i.INP", "r", stdin);
    freopen("o.OUT", "w", stdout);
    sangNguyenTo();
    ll q;
    cin >> q;
    for(int i = 0; i < q; ++i){
        cin >> l >> r;
        calMinMax();
        ll res;
        res = sdigit();
        cout << res << "\n";
    }
    return 0;
}
