#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

ll m, n, a[maxN][maxN];
ll maxCot[maxN] = {};

void readData(){
    cin >> m >> n;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }
}

void maxMin(){
    for(int i = 0; i < n; ++i) maxCot[i] = LLONG_MIN;

    ll minn = LLONG_MAX;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            maxCot[j] = max(maxCot[j], a[i][j]);
        }
    }

    for(int i = 0; i < n; ++i){
        minn = min(minn, maxCot[i]);
    }

    for(int i = 0; i < n; ++i){
        if(maxCot[i] == minn) cout << i + 1 << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    maxMin();
    return 0;
}
