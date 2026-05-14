#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

ll m, n, q, k;
ll a[maxN][maxN];
ll dp[305][305][305] = {};

void readData(){
    cin >> n >> m >> q >> k;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> a[i][j];
        }
    }
}

void sub3(){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            for(int r = 0; r < k; ++r){
                dp[i][j][r] = max(dp[i-1][j][r], dp[i][j-1][r]);
            }
            ll du = a[i][j] % k;
            dp[i][j][du] += 1;
        }
    }
    for(int i = 0; i < q; ++i){
        ll tv;
        cin >> tv;
        cout << dp[n][m][tv] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ROBOT.INP", "r", stdin);
    freopen("ROBOT.OUT", "w", stdout);
    readData();
    if(m <= 300 && n <= 300 && k <= 300) sub3();
    return 0;
}
