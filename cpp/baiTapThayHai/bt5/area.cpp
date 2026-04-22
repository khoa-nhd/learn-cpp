#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

ll m, n;
ll a[maxN][maxN] = {};

void readData(){
    cin >> m >> n;
    char c;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cin >> c;
            if(c == '#'){
                a[i][j] = -1;
            }
        }
    }
}

void danh(int i, int j){
    a[i][j] = 1;
    if(i - 1 >= 0 && a[i-1][j] == 0) danh(i-1, j);
    if(i + 1 < m && a[i+1][j] == 0) danh(i+1, j);
    if(j - 1 >= 0 && a[i][j-1] == 0) danh(i, j-1);
    if(j + 1 < n && a[i][j+1] == 0) danh(i, j + 1);
}

ll areas(){
    ll res = 0;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(a[i][j] == 0){
                danh(i, j);
                res += 1;
            }
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("AREA.INP", "r", stdin);
    freopen("AREA.OUT", "w", stdout);
    readData();
    ll res;
    res = areas();
    cout << res;
    return 0;
}
