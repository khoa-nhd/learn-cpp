#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[3][3];
bool taken[3] = {};
ll sum = 0;
vector<ll> curr;
ll res = LLONG_MAX;

void readData(){
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            cin >> a[i][j];
            sum += a[i][j];
        }
    }
}

void cal(){
    ll val = 0;
    val = a[0][curr[0]] + a[1][curr[1]] + a[2][curr[2]];
    val = sum - val;
    res = min(val, res);
}

void phanloai(){
    if(curr.size() == 3){
        cal();
        return;
    }
    for(int i = 0; i < 3; ++i){
        if(!taken[i]){
            taken[i] = true;
            curr.push_back(i);
            phanloai();
            taken[i] = false;
            curr.pop_back();
        }
    }
}

int main(){
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    phanloai();
    cout << res;
    return 0;
}
