#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[40][40] = {};
ll dr[4] = {0, -1, 0, 1};
ll dc[4] = {-1, 0, 1, 0};

void readData(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            char temp;
            cin >> temp;
            if(temp == '.') a[i][j] = 1;
        }
    }
}

bool valid(ll r, ll c){
    return (r > 0 && c > 0 && r <= n && c <= n);
}

ll dfs(ll r, ll c){
    ll res = 0;
    if(a[r][c] == 1){
        a[r][c] = 2;
        for(int i = 0; i < 4; ++i){
            ll x = r + dr[i];
            ll y = c + dc[i];
            if(a[x][y] == 0){
                res += 1;
//                cout << x << " " << y << "\n";
            }
            if(valid(x, y) && a[x][y] == 1) res += dfs(x, y);
        }
    }
    return res;
}

ll mirror(){
    ll soGuong = 0;
    ll res = 0;
    res = dfs(1, 1) + dfs(n, n);
    res = (res - 4) * 3 * 3;
    return res;
}

int main(){
    freopen("MIRROR.INP", "r", stdin);
    freopen("MIRROR.OUT", "w", stdout);
    readData();
    ll res;
    res = mirror();
    cout << res;
    return 0;
}
