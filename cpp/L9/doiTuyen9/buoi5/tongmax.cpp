#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

ll m, n, a[maxN][maxN];
ll b[maxN] = {};
ll c[maxN];

void readData(){
    cin >> m >> n;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }
}

void tong(){
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            b[i] += a[i][j];
        }
    }
    for(int i = 0; i < m; ++i){
        cout << b[i] << " ";
    }
    cout << "\n";
}

void maxx(){
    for(int i = 0; i < m; ++i) c[i] = LLONG_MIN;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            c[i] = max(c[i], a[i][j]);
        }
    }
    for(int i = 0; i < m; ++i){
        cout << c[i]<< " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    tong();
    maxx();
    return 0;
}
