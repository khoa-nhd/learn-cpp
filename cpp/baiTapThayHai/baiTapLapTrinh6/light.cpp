#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll n;
ull s[100] = {};
ull e[100] = {};

void hangTamGiac(){
    ull mu = 1;
    for(int i = 1; i <= 61; ++i){
        s[i] = mu;
        mu *= 2;
    }
    mu = 2;
    for(int i = 1; i <= 61; ++i){
        e[i] = mu - 1;
        mu *= 2;
    }
}

ll timSTTTamGiac(ll target){
    ll res = -1;
    ll d = 1;
    ll c = 61;
    while(d <= c){
        ll half = (d + c) / 2;
        if(e[half] >= target){
            res = half;
            c = half - 1;
        } else{
            d = half + 1;
        }
    }
    return res;
}

ll light(ll n){
    if(n == 1) return 1;
    ll stt = timSTTTamGiac(n);
    ll soHangTamGiac = e[stt] - s[stt] + 1;
    ll hang = n - s[stt] + 1;
    ll soHangQuayVe = e[stt-1] - s[stt-1] + 1;
    if(hang > soHangTamGiac / 2) return 2 * light(n-soHangQuayVe);
    else return light(n-soHangQuayVe);
}

int main(){
    freopen("LIGHT.INP", "r", stdin);
    freopen("LIGHT.OUT", "w", stdout);
    cin >> n;
    hangTamGiac();
    ll res;
    res = light(n);
    cout << res;
    return 0;
}
