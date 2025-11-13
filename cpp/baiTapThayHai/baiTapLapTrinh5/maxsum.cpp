#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

ll m, n, a[maxN][maxN] = {};

void readData(){
    cin >> m >> n;
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }
}

ll maxSum(){
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            ll cong = 0;
            if(a[i][j] % 2 == 0) cong = a[i][j];
            a[i][j] = max(a[i-1][j], a[i][j-1]) + cong;
        }
    }
    return a[m][n];
}

int main(){
    freopen("MAXSUM.INP", "r", stdin);
    freopen("MAXSUM.OUT", "w", stdout);
    readData();
    ll res;
    res = maxSum();
    cout << res;
    return 0;
}
