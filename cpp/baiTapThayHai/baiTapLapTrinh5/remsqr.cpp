#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m, n, a[105][105] = {};

void readData(){
    cin >> m >> n;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            char temp;
            cin >> temp;
            if(temp == '#'){
                a[i][j] = 1;
            }
        }
    }
}

void danh(int i, int j){
    a[i][j] = 0;
    if(i - 1 >= 0 && a[i-1][j] == 1) danh(i-1, j);
    if(i + 1 < m && a[i+1][j] == 1) danh(i+1, j);
    if(j - 1 >= 0 && a[i][j-1] == 1) danh(i, j-1);
    if(j + 1 < n && a[i][j+1] == 1) danh(i, j+1);
}

ll remsqr(){
    ll res = 0;
//    for(int i = 0; i < m; ++i){
//        for(int j = 0; j < n; ++j){
//            cout << a[i][j];
//        }
//        cout << "\n";
//    }
//    cout << "\n";
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(a[i][j] == 1){
                danh(i, j);
                res += 1;
//                for(int i = 0; i < m; ++i){
//                    for(int j = 0; j < n; ++j){
//                        cout << a[i][j];
//                    }
//                    cout << "\n";
//                }
//                cout << "\n";
            }
        }
    }
    return res;
}

int main(){
    freopen("REMSQR.INP", "r", stdin);
    freopen("REMSQR.OUT", "w", stdout);
    readData();
    ll res;
    res = remsqr();
    cout << res;
    return 0;
}
