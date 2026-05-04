#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll h, w;
ll a[1005][1005] = {};
ll ci[] = {-1, 0, 1, 0};
ll cj[] = {0, 1, 0, -1};

void readData(){
    cin >> h >> w;
    for(int i = 1; i <= h; ++i){
        for(int j = 1; j <= w; ++j){
            cin >> a[i][j];
        }
    }
}

ll surface(){
    ll res = 2 * w * h;
    for(int i = 1; i <= h; ++i){
        for(int j = 1; j <= w; ++j){
            for(int k = 0; k < 4; ++k){
                ll x = i + ci[k];
                ll y = j + cj[k];
                if(a[i][j] > a[x][y]){
                    res += a[i][j] - a[x][y];
                }
            }
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SURFACE.INP", "r", stdin);
    freopen("SURFACE.OUT", "w", stdout);
    readData();
    ll res;
    res = surface();
    cout << res;
    return 0;
}
