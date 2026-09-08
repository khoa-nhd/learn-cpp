#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 2005

int dp[2005][3][2005] = {};
int mod = 1e9 + 7;
int high, nn;
int dfs(int pos, int dir, int p){
    if(pos > nn) return 1;
    if(p != -1 && dp[pos][dir][p] != -1){
        cout << pos << " " << dir << " " << p << "\n";
       return dp[pos][dir][p];
    }
    int res = 0;
    if(dir == 2 && p == -1){
        for(int i = 0; i <= high; ++i){
            res += dfs(pos+1, 2, i);
            res %= mod;
        }
    } else if(dir == 2){
        for(int i = 0; i <= high; ++i){
            if(i == p) continue;
            res += dfs(pos+1, (p < i), i);
            res %= mod;
        }
    } else if(dir){
        for(int i = 0; i < p; ++i){
            res += dfs(pos+1, 0, i);
            res %= mod;
        }
    } else{
        for(int i = p+1; i <= high; ++i){
            res += dfs(pos+1, 1, i);
            res %= mod;
        }
    }
    return dp[pos][dir][p] = res;
}
int zigZagArrays(int n, int l, int r) {
    memset(dp, -1, sizeof(dp));
    high = r - l;
    nn = n;
    int res = dfs(1, 2, -1);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("i.INP", "r", stdin);
    freopen("o.OUT", "w", stdout);
    cout << zigZagArrays(42, 195, 1455);
    return 0;
}
