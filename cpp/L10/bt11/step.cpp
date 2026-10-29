#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;
ll mod = 1e9 + 7;
ll mu2[80] = {};

void thaphanoi(ll dia, ll tu, ll den, ll tg){
    if(dia == 1){
        cout << dia << " " << tu << " " << den << "\n";
        return;
    }
    thaphanoi(dia - 1, tu, tg, den);
    cout << dia << " " << tu << " " << den << "\n";
    thaphanoi(dia - 1, tg, den, tu);
}

void cal(){
    mu2[0] = 1;
    for(int i = 1; i <= 60; ++i){
        mu2[i] = 2 * mu2[i-1];
//        mu2[i] %= mod;
    }
}

void sol(ll buoc, ll dia, ll tu, ll den, ll tg){
    if(k == buoc + mu2[dia-1]){
        cout << dia << " " << tu << " " << den;
        return;
    }
    if(k < buoc + mu2[dia-1]){
        sol(buoc, dia-1, tu, tg, den);
    } else{
        sol(buoc + mu2[dia-1], dia - 1, tg, den, tu);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("STEP.INP", "r", stdin);
    freopen("STEP.OUT", "w", stdout);
//    thaphanoi(4, 1, 3, 2);
    cin >> n >> k;
    cal();
    sol(0, n, 1, 3, 2);
    return 0;
}
