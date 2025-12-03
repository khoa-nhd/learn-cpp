#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

ll m, n;
ll dr[4] = {0, -1, 0, 1};
ll dc[4] = {-1, 0, 1, 0};
char a[maxN][maxN] = {};
bool mark[maxN][maxN] = {};
vector<pair<ll, ll>> chuong;

void readData(){
    cin >> m >> n;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }
}

bool valid(ll r, ll c){
    return (r >= 0 && c >= 0 && r < m && c < n);
}

void dfs(ll r, ll c, ll soChuong){
    if(a[r][c] == 'f') chuong[soChuong].first += 1;
    else if(a[r][c] == 'c') chuong[soChuong].second += 1;
    mark[r][c] = true;
    for(int i = 0; i < 4; ++i){
        ll x = r + dr[i];
        ll y = c + dc[i];
        if(valid(x, y) && a[x][y] != '#' && !mark[x][y]){
            dfs(x, y, soChuong);
        }
    }
}

void farm(){
    ll cao = 0;
    ll ga = 0;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(a[i][j] == '#') mark[i][j] = true;
            if(!mark[i][j]){
                chuong.push_back({0, 0});
                dfs(i, j, chuong.size()-1);
            }
        }
    }

    for(pair<ll, ll> x : chuong){
//        cout << x.first << " " << x.second << "\n";
        if(x.first >= x.second) cao += x.first;
        else ga += x.second;
    }

    cout << cao << " " << ga;
}

int main(){
    freopen("FARM.INP", "r", stdin);
    freopen("FARM.OUT", "w", stdout);
    readData();
    farm();
    return 0;
}
