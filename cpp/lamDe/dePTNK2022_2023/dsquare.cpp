#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll l, r;
vector<ll> v;
ll res = 0;
ll cp = 0;

void chinhPhuong(){
    for(ll i = l; i <= r; ++i){
        bool co = false;
        for(int j = 2; j * j <= i; ++j){
            if(i % (j * j) == 0) co = true;
        }
        if(co){
            res += r - l - cp;
            cp += 1;
        }
        else v.push_back(i);
    }
}

void koChinhPhuong(){
    for(int i = 0; i < v.size(); ++i){
        for(int j = i+1; j < v.size(); ++j){
            if(__gcd(v[i], v[j]) > 1){
                res += 1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    cin >> l >> r;
    chinhPhuong();
    koChinhPhuong();
    cout << res;
    return 0;
}
