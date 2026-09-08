#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

vector<pair<ll, ll>> yenngua;
ll maxdong[maxN], mincot[maxN];
ll m, n, a[maxN][maxN];

void readData(){
    cin >> m >> n;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }
}

void sol(){
    for(int i = 0; i < maxN; ++i){
        maxdong[i] = LLONG_MIN;
        mincot[i] = LLONG_MAX;
    }
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            maxdong[i] = max(maxdong[i], a[i][j]);
            mincot[j] = min(mincot[j], a[i][j]);
        }
    }

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(a[i][j] == maxdong[i] && a[i][j] == mincot[j]){
                yenngua.push_back({i+1, j+1});
            }
        }
    }
}

void output(){
    if(yenngua.size() == 0){
        cout << 0 << "\n";
        return;
    }
    for(int i = 0; i < yenngua.size(); ++i){
        cout << yenngua[i].first << " " << yenngua[i].second << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    sol();
    output();
    return 0;
}
