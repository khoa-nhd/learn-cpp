#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s, t;
ll cntT[10] = {};
ll cntS[10] = {};

void demT(){
    for(char x : t){
        ll so = x - '0';
        cntT[so] += 1;
    }
    cntT[2] += cntT[5];
    cntT[6] += cntT[9];
}

ll stickers(){
    for(char x : s){
        ll so = x - '0';
        cntS[so] += 1;
    }
    cntS[2] += cntS[5];
    cntS[6] += cntS[9];
    ll res = -1;
    for(int i = 0; i < 10; ++i){
        if(i == 5 ||i == 9) continue;
        if(cntS[i] != 0){
            if(res == -1) res = cntT[i] / cntS[i];
            else res = min(res, cntT[i] / cntS[i]);
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    cin >> t >> s;
    demT();
    ll res;
    res = stickers();
    cout << res;
    return 0;
}
