#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> v[205];

void sol(){
    v[2] = {1, 2, 2, 1, 2, 1, 1, 2};
    v[3] = {1, 1, 2, 1, 2, 3, 1, 3, 2, 2, 3, 3};
    for(int i = 4; i <= 200; ++i){
        v[i] = v[i-2];
        for(int j = 0; j < v[2].size(); ++j){
            v[i].push_back(v[2][j] + i - 2);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    sol();
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        ll n;
        cin >> n;
        for(int i = 0; i < v[n].size(); ++i) cout << v[n][i] << " ";
        cout << "\n";
    }
    return 0;
}
