#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

ll m, n;
ll h[maxN][maxN] = {};

void readData(){
    cin >> m >> n;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cin >> h[i][j];
        }
    }
}

bool checkUp(int i, int j){
    for(int k = i; k >= 0; --k){
        if(h[i][j] < h[k][j]) return false;
    }
    return true;
}

bool checkDown(int i, int j){
    for(int k = i; k < m; ++k){
        if(h[i][j] < h[k][j]) return false;
    }
    return true;
}

bool checkLeft(int i, int j){
    for(int k = j; k >= 0; --k){
        if(h[i][j] < h[i][k]) return false;
    }
    return true;
}

bool checkRight(int i, int j){
    for(int k = j; k < n; ++k){
        if(h[i][j] < h[i][k]) return false;
    }
    return true;
}

ll building(){
    ll res = 0;
    for(int i = 1; i < m; ++i){
        for(int j = 1; j < n; ++j){
            if(!checkDown(i, j) && !checkLeft(i, j) && !checkRight(i, j) && !checkUp(i, j)) res += 1;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BUILDING.INP", "r", stdin);
    freopen("BUILDING.OUT", "w", stdout);
    readData();
    ll res;
    res = building();
    cout << res;
    return 0;
}
