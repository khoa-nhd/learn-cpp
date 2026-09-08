#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll w, h, n;
bool colored[105][105] = {};

ll coloring(){
    cin >> w >> h >> n;
    for(int i = 0; i < n; ++i){
        ll x, y, a;
        cin >> x >> y >> a;
        if(a == 1){
            for(int i = 1; i <= w; ++i){
                for(int j = 1; j <= h; ++j){
                    if(i <= x) colored[i][j] = true;
                }
            }
        } else if(a == 2){
            for(int i = 1; i <= w; ++i){
                for(int j = 1; j <= h; ++j){
                    if(i > x) colored[i][j] = true;
                }
            }
        } else if(a == 3){
            for(int i = 1; i <= w; ++i){
                for(int j = 1; j <= h; ++j){
                    if(j <= y) colored[i][j] = true;
                }
            }
        } else{
            for(int i = 1; i <= w; ++i){
                for(int j = 1; j <= h; ++j){
                    if(j > y) colored[i][j] = true;
                }
            }
        }
    }
    ll res = 0;
    for(int i = 1; i <= w; ++i){
        for(int j = 1; j <= h; ++j){
            if(!colored[i][j]) res += 1;
//            cout << colored[i][j] << " ";
        }
//        cout << "\n";
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    ll res;
    res = coloring();
    cout << res;
    return 0;
}
