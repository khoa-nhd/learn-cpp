#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 205

ll a[maxN][maxN];

ll nhiSangThap(ll x){
    ll res = 0;
    ll mu2 = 1;
    while(x > 0){
        if(x % 10 == 1) res += mu2;
        x /= 10;
        mu2 *= 2;
    }
    return res;
}

void readData(){
    cin >> m >> n;
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            ll x;
            cin >> x;
            x = nhiSangThap(x);
            a[m][n] = x;
        }
    }
}

void sol(){
    for(int i = 1; i < m; ++i){

    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("i.INP", "r", stdin);
    freopen("o.OUT", "w", stdout);
    readData();

    return 0;
}
