#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cu[55][55] = {};
bool moi[55][55] = {};
ll m, n;

void readData(){
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        ll a, b;
        cin >> a >> b;
        cu[a][b] = true;
        cu[b][a] = true;
    }
}

bool check(){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(!cu[i][j]) return false;
        }
    }
    return true;
}

void ganMC(){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            moi[i][j] = cu[i][j];
        }
    }
}

void ganCM(){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cu[i][j] = moi[i][j];
        }
    }
}

void in(){
    cout << "\n";
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cout << moi[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void fridlist(){
    for(int i = 1; i <= n; ++i) cu[i][i] = true;
//    ganMC();
//    in();
    vector<ll> res;
    while(!check()){
        ganMC();
        set<pair<ll, ll>> qhxl;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(cu[i][j]){
                    for(int k = 1; k <= n; ++k){
                        if(cu[j][k] && !cu[i][k]){
                            moi[i][k] = true;
                            moi[k][i] = true;
                            qhxl.insert({i, k});
                        }
                    }
                }
            }
        }
//        cout << "\n";
//        in();
        ganCM();
        res.push_back(qhxl.size());
    }
    cout << res.size() << "\n";
    for(ll x : res) cout << x/2 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("FRIDLIST.INP", "r", stdin);
    freopen("FIRDLIST.OUT", "w", stdout);
    readData();
    fridlist();
    return 0;
}
