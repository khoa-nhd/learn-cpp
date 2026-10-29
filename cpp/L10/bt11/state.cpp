#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;
ll state[80] = {};
ll mu2[80] = {};

void cal(){
    mu2[0] = 1;
    for(int i = 1; i <= 60; ++i){
        mu2[i] = 2 * mu2[i-1];
//        mu2[i] %= mod;
    }
}

void sol(ll buoc, ll dia, ll tu, ll den, ll tg){
    if(k == buoc + mu2[dia-1]){
        state[dia] = den;
        for(int i = 1; i < dia; ++i) state[i] = tg;
        return;
    }
    if(k < buoc + mu2[dia-1]){
        sol(buoc, dia-1, tu, tg, den);
    } else{
        state[dia] = den;
        for(int i = 1; i < dia; ++i) state[i] = tg;
        sol(buoc + mu2[dia-1], dia - 1, tg, den, tu);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("STATE.INP", "r", stdin);
    freopen("STATE.OUT", "w", stdout);
    cin >> n >> k;
    cal();
    for(int i = 1; i <= n; ++i) state[i] = 1;
    sol(0, n, 1, 3, 2);
    for(int i = 1; i <= n; ++i){
        cout << state[i] << " ";
    }
    return 0;
}
