#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n;
char a[15][maxN] = {};
vector<pair<ll, ll>> buocDi;
int possible[15][maxN] = {}; // 0: chưa thử; 2: không thể

void readData(){
    cin >> n;
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
            if(a[i][j] == 'X') possible[i][j] = 2;
        }
    }
}

void output(){
//    for(auto x : buocDi){
//        cout << x.first << " " << x.second << "\n";
//    }
    vector<pair<ll, ll>> res;
    ll start = -1;
    ll duration = 0;
    for(int i = 1; i < buocDi.size(); ++i){
        if(buocDi[i].first < buocDi[i-1].first || buocDi[i].first == 0){
            if(start == -1) start = i - 1;
            duration += 1;
        } else{
            if(start != -1) res.push_back({start, duration});
            duration = 0;
            start = -1;
        }
    }
    if(start != -1) res.push_back({start, duration});
    cout << res.size() << "\n";
    for(pair<ll, ll> x : res){
        cout << x.first << " " << x.second << "\n";
    }
}

bool valid(ll i, ll j){
    return (i >= 0 && j >= 0 && i <= 9 && j < n);
}

bool dfs(int i, int j){
    if(possible[i][j] == 2) return false;
    buocDi.push_back({i, j});
    if(j == n-1){
        return true;
    }
    if(i == 9){
        if(a[i][j+1] != 'X'){
            if(dfs(i, j+1)){
                return true;
            }
        }
        if(valid(i-1, j+1) && a[i-1][j+1] != 'X'){
            if(dfs(i-1, j+1)){
                return true;
            }
        }
    } else if(i == 0){
        if(a[i][j+1] != 'X'){
            if(dfs(i, j+1)){
                return true;
            }
        }
        if(valid(i+1, j+1) && a[i+1][j+1] != 'X'){
            if(dfs(i+1, j+1)){
                return true;
            }
        }
    } else{
        if(valid(i+1, j+1) && a[i+1][j+1] != 'X'){
            if(dfs(i+1, j+1)){
                return true;
            }
        }
        if(valid(i-1, j+1) && a[i-1][j+1] != 'X'){
            if(dfs(i-1, j+1)){
                return true;
            }
        }
    }
    possible[i][j] = 2;
    buocDi.pop_back();
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BIRD.INP", "r", stdin);
    freopen("BIRD.OUT", "w", stdout);
    readData();
    dfs(9, 0);
    output();
    return 0;
}
