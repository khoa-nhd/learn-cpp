#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

ll n, a[maxN][maxN] = {};

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }
}

ll dgCheoChinh(){
    ll res = 0;
    for(int i = 0; i < n; ++i){
        res += a[i][i];
    }
    return res;
}

ll dgCheoPhu(){
    ll res = 0;
    for(int i = 0; i < n; ++i){
        res += a[i][(n-1) - i];
    }
    return res;
}

ll satTrenDuoiDgCheoChinh(){
    ll res = 0;
    for(int i = 0; i < n-1; ++i){
        res += a[i][i+1];
    }
    for(int i = 1; i < n; ++i){
        res += a[i][i-1];
    }
    return res;
}

ll satTrenDuoiDgCheoPhu(){
    ll res = 0;
    for(int i = 0; i < n-1; ++i){
        res += a[i][(n-1) - i - 1];
    }
    for(int i = 1; i < n; ++i){
        res += a[i][n - i];
    }
    return res;
}

ll trenDgCheoChinh(){
    ll res = 0;
    for(int i = 0; i < n - 1; ++i){
        for(int j = i + 1; j < n; ++j){
            res += a[i][j];
        }
    }
    return res;
}

ll duoiDgCheoPhu(){
    ll res = 0;
    for(int i = 1; i < n; ++i){
        for(int j = n - i; j < n; ++j){
            res += a[i][j];
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    ll a = dgCheoChinh();
    ll b = dgCheoPhu();
    ll c = satTrenDuoiDgCheoChinh();
    ll d = satTrenDuoiDgCheoPhu();
    ll e = trenDgCheoChinh();
    ll f = duoiDgCheoPhu();
    cout << a << "\n";
    cout << b << "\n";
    cout << c << "\n";
    cout << d << "\n";
    cout << e << "\n";
    cout << f << "\n";
    return 0;
}
