#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x;
bool used[10];

void sodoclap(){
    for(int i = 0; i < 10; ++i) used[i] = false;

    string strX = to_string(x);
    used[strX[0] - '0'] = true;
    string res;
    string res2;
    res.push_back(strX[0]);
//    cout << strX << "\n";
    bool lonHon = false;
    int j;
    ll loop = strX.size();
    bool lamlai = false;
    for(int i = 1; i < loop; ++i){
        if(lonHon) j = 0;
        else(j = strX[i] - '0');
        for(j; j < 10; ++j){
            if(!used[j]){
                res.push_back(j + '0');
                used[j] = true;
                break;
            }
            if(j == 9){
                if(strX[0] == 9){
                    for(int k = 0; k < 10; ++k){
                    if(!used[k]){
                            res.push_back(k + '0');
                            used[k] = true;
                            lonHon = true;
                            loop += 1;
                            break;
                        }
                    }
                } else{
                    strX[0] = (strX[0] - '0') + 1 + '0';
                    lamlai = true;
                }
            }
        }
        if(lamlai) break;
        if(res[i] - '0' > strX[i] - '0') lonHon = true;
    }

    for(int i = 0; i < 10; ++i) used[i] = false;
    res2.push_back(strX[0]);
    used[res2[0] - '0'] = true;
    if(lamlai){
        for(int i = 1; i < loop; ++i){
            for(int j = 0; j < 10; ++j){
                if(!used[j]){
                    res2.push_back(j + '0');
                    used[j] = true;
                    break;
                }
            }
        }
    }

    if(lamlai) cout << res2;
    else cout << res;
}

int main(){
    freopen("i.INP", "r", stdin);
    freopen("o.OUT", "w", stdout);
    cin >> x;
    x += 1;
    sodoclap();
    return 0;
}
