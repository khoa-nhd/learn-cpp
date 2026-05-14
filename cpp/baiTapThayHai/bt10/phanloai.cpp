#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[3][3];
bool taken[3];
ll maxx = 0;
ll sum = 0;

void readData(){
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            cin >> a[i][j];
            sum += a[i][j];
        }
    }
}

void phanloai(ll dong, ll tong){
    if(dong >= 3){
        maxx = max(tong, maxx);
        return;
    }
    for(int i = 0; i < 3; ++i){
        if(!taken[i]){
            taken[i] = true;
            phanloai(dong+1, tong+a[dong][i]);
            taken[i] = false;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PHANLOAI.INP", "r", stdin);
    freopen("PHANLOAI.OUT", "w", stdout);
    readData();
    phanloai(0, 0);
    cout << sum - maxx;
    return 0;
}
