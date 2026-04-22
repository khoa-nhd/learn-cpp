#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m, n;
ll a[1005], b[1005];
ll dp[1005][1005] = {};

void readData(){
    cin >> m >> n;
    for(int i = 1; i <= m; ++i){
        cin >> a[i];
    }
    for(int i = 1; i <= n; ++i){
        cin >> b[i];
    }
}

ll num1(ll x){
    ll res = 0;
    while(x > 0){
        res += x % 2;
        x /= 2;
    }
    return res;
}

void convert(){
    for(int i = 1; i <= m; ++i){
        a[i] = num1(a[i]);
//        cout << a[i] << " ";
    }
//    cout << "\n";
    for(int i = 1; i <= n; ++i){
        b[i] = num1(b[i]);
//        cout << b[i] << " ";
    }
//    cout << "\n";
}

ll circuits(){
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            if(a[i] == b[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            } else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
//    cout << "\n";
//    for(int i = 1; i <= m; ++i){
//        for(int j = 1; j <= n; ++j){
//            cout << dp[i][j] << " ";
//        }
//        cout << "\n";
//    }
    return dp[m][n];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CIRCUITS.INP", "r", stdin);
    freopen("CIRCUITS.OUT", "w", stdout);
    readData();
    convert();
    ll res;
    res = circuits();
    cout << res;
    return 0;
}
