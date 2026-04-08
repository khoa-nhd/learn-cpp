#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m, n;
ll a[1005][1005];
ll pre[1005][1005] = {};
ll sum = 0;

void readData(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            cin >> a[i][j];
            sum += a[i][j];
        }
    }
}

void calPre(){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + a[i][j];
        }
    }
//    for(int i = 1; i <= n; ++i){
//        for(int j = 1; j <= m; ++j){
//            cout << pre[i][j] << " ";
//        }
//        cout << "\n";
//    }
}

void dowry(){
    if(sum % 3 != 0){
        cout << "NO";
        return;
    }
    for(int i = 1; i < n; ++i){
        if(pre[i][m] == sum / 3){
            for(int j = 1; j < m; ++j){
                if(pre[n][j] - pre[i][j] == sum / 3){
                    cout << "N " << i << "\n";
                    cout << "D " << j << "\n";
                    return;
                }
            }
            for(int j = i+1; j < n; ++j){
                if(pre[j][m] - pre[i][m] == sum / 3){
                    cout << "N " << i << "\n";
                    cout << "N " << j << "\n";
                    return;
                }
            }
        }
    }
    for(int i = 1; i < m; ++i){
        if(pre[n][i] == sum / 3){
            for(int j = 1; j < n; ++j){
                if(pre[j][m] - pre[j][i] == sum / 3){
                    cout << "D " << i << "\n";
                    cout << "N " << j << "\n";
                    return;
                }
            }
            for(int j = i+1; j < m; ++j){
                if(pre[n][j] - pre[n][i] == sum / 3){
                    cout << "D " << i << "\n";
                    cout << "D " << j << "\n";
                    return;
                }
            }
        }
    }
    cout << "NO";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    calPre();
    dowry();
    return 0;
}
