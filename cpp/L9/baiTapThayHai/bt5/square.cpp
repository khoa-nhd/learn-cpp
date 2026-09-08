#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

ll m, n;
char a[maxN][maxN] = {};
ll dp[maxN][maxN] = {};

void readData(){
    cin >> m >> n;
    for(int i = 1; i <= m; ++i){
        string temp;
        cin >> temp;
        for(int j = 1; j <= n; ++j){
            a[i][j] = temp[j-1];
        }
    }
}

ll square(){
    ll res = 0;
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
//            cout << a[i][j] << " ";
            if(a[i][j] == '.') dp[i][j] == 0;
            else {
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                res = max(res, dp[i][j]);
            }
//            cout << dp[i][j] << " ";
        }
//        cout << "\n";
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SQUARE.INP", "r", stdin);
    freopen("SQUARE.OUT", "w", stdout);
    readData();
    ll res = square();
    cout << res;
    return 0;
}
