#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;
bool homnay[60][60] = {};

void readData(){
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        ll a, b;
        cin >> a >> b;
        homnay[a][b] = true;
        homnay[b][a] = true;
    }
}

bool checkFinish(){
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(!homnay[i][j]) return false;
        }
    }
    return true;
}

void fridlist(){
    vector<ll> res;
    while(!checkFinish()){
        ll soKetNoi = 0;
        bool ngaymai[60][60];
//        for(int i = 0; i < 51; ++i){
//            for(int j = 0; j < 51; ++j){
//                ngaymai[i][j] = homnay[i][j];
//                cout << ngaymai[i][j] << " ";
//            }
//            cout << "\n";
//        }
//        cout << "\n";
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(homnay[i][j] == true){
                    for(int k = 1; k <= n; ++k){
                        if(homnay[j][k] == true){
                            if(homnay[i][k] == false){
                                ngaymai[i][k] = true;
                                soKetNoi += 1;
                            }
                            if(homnay[k][i] == false){
                                ngaymai[k][i] = true;
                                soKetNoi += 1;
                            }
                        }
                    }
                }
            }
        }
        res.push_back(soKetNoi);
        for(int i = 0; i < 51; ++i){
            for(int j = 0; j < 51; ++j){
                homnay[i][j] = ngaymai[i][j];
            }
        }
    }
    cout << res.size() << "\n";
    for(int i = 0; i < res.size(); ++i){
        cout << res[i] << "\n";
    }
}

int main(){
    freopen("i.INP", "r", stdin);
    freopen("o.OUT", "w", stdout);
    readData();
    fridlist();
    return 0;
}
