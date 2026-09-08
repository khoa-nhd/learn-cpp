#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

ll n, m;
ll a[maxN][maxN] = {};
ll ans[maxN][maxN] = {};
ll ci[4] = {-1, 0, 1, 0};
ll cj[4] = {0, 1, 0, -1};

void readData(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            char temp;
            cin >> temp;
            if(temp == 'N') a[i][j] = 0;
            else if(temp == 'E') a[i][j] = 1;
            else if(temp == 'S') a[i][j] = 2;
            else a[i][j] = 3;
        }
    }
}

bool valid(ll i , ll j){
    return(i >= 0 && j >= 0 && i < n && j < m);
}

bool dfs(ll i, ll j){
    if(ans[i][j] == 2){
        ans[i][j] = 1;
        return true;
    }
    ll nexti = ci[a[i][j]] + i;
    ll nextj = cj[a[i][j]] + j;
    ans[i][j] = 2;
    if(!valid(nexti, nextj)){
        ans[i][j] = -1;
        return false;
    }
    bool quayLai = dfs(nexti, nextj);
    if(quayLai) ans[i][j] = 1;
    else ans[i][j] = -1;
    return quayLai;
}

ll itable(){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(ans[i][j] == 0){
                dfs(i, j);
            }
        }
    }
    ll res = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(ans[i][j] == 1) res += 1;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ITABLE.INP", "r", stdin);
    freopen("ITABLE.OUT", "w", stdout);
    readData();
    ll res;
    res = itable();
    cout << res;
    return 0;
}
