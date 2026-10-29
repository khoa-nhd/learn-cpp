#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[80] = {};

void readData(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
}

ll mu2[80] = {};

void cal(){
    mu2[0] = 1;
    for(int i = 1; i <= 60; ++i){
        mu2[i] = 2 * mu2[i-1];
//        mu2[i] %= mod;
    }
}

void sol(ll dia, ll tu, ll den, ll tg, ll buoc){
    if(dia == 1){
        if(a[dia] == tu){
            cout << buoc;
        } else{
            cout << buoc + 1;
        }
        return;
    }
    if(a[dia] == tu){
        sol(dia - 1, tu, tg, den, buoc);
    } else if (a[dia] == den){
        sol(dia - 1, tg, den, tu, buoc + mu2[dia-1]);
    } else{
        cout << -1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("POSITION.INP", "r", stdin);
    freopen("POSITION.OUT", "w", stdout);
    readData();
    cal();
    sol(n, 1, 3, 2, 0);
    return 0;
}
