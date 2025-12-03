#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

pair<ll, ll> s, e;
ll m, n;
ll dr[4] = {0, -1, 0, 1};
ll dc[4] = {-1, 0, 1, 0};
char huongDi[4] = {'W', 'N', 'E', 'S'};
char a[maxN][maxN];
bool mark[maxN][maxN] = {};
vector<ll> res;

void readData(){
    cin >> m >> n;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
            if(a[i][j] == '*'){
                s.first = i;
                s.second = j;
            }
            if(a[i][j] == '.' && (i == 0 || i == m-1 || j == 0 || j == n-1)){
                e.first = i;
                e.second = j;
            }
        }
    }
}

bool valid(ll r, ll c){
    return (r >= 0 && c >= 0 && r < m && c < n);
}

bool dfs(ll r, ll c, int huong){
    mark[r][c] = true;
    if(huong != -1) res.push_back(huong);

    if(r == e.first && c == e.second){
        return true;
    }

    for(int i = 0; i < 4; ++i){
        ll x = r + dr[i];
        ll y = c + dc[i];
        if(valid(x, y) && !mark[x][y] && a[x][y] == '.'){
            if(dfs(x, y, i)) return true;
        }
    }

    res.pop_back();
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("LABYRINTH.INP", "r", stdin);
    freopen("LABYRINTH.OUT", "w", stdout);
    readData();
    bool possible = dfs(s.first, s.second, -1);
    for(ll x : res){
        cout << huongDi[x];
    }
    return 0;
}
