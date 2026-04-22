#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

ll a[maxN][maxN] = {};
bool marked[maxN][maxN] = {};
ll n, k;
ll di[4] = {0, -1, 0, 1};
ll dj[4] = {-1, 0, 1, 0};
vector<ll> res;

void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        ll r, c, p;
        cin >> r >> c >> p;
        a[r][c] = p;
    }
}

bool valid(int i, int j){
    return (i >= 0 && j >= 0 && i < maxN && j < maxN);
}

ll dfs(int i, int j){
    marked[i][j] = true;
    ll ans = 0;
    ans += a[i][j];
    for(int k = 0; k < 4; ++k){
        ll x = i + di[k];
        ll y = j + dj[k];
        if(valid(x, y) && a[x][y] != 0 && !marked[x][y]){
            ans += dfs(x, y);
        }
    }
    return ans;
}

void nhom(){
    for(int i = 0; i < maxN; ++i){
        for(int j = 0; j < maxN; ++j){
            if(a[i][j] == 0) marked[i][j] = true;
            if(!marked[i][j]){
                res.push_back(dfs(i, j));
            }
        }
    }
}

bool cmp(ll x, ll y){
    return x > y;
}

ll output(){
    ll ans = 0;
    sort(res.begin(), res.end(), cmp);
    for(int i = 0; i < k && i < res.size(); ++i){
        ans += res[i];
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TREASURE.INP", "r", stdin);
    freopen("TREASURE.OUT", "w", stdout);
    readData();
    nhom();
    ll ans;
    ans = output();
    cout << ans;
    return 0;
}
