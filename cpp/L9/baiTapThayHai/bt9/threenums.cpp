#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, x, y;
pair<bool, vector<ll>> co[maxN] = {};
ll a[maxN];
vector<ll> uoc;
vector<vector<ll>> pot;

void readData(){
    cin >> n >> x >> y;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void threenums(){
    for(int i = 1; i * i <= y; ++i){
        if(i * i == y) uoc.push_back(i);
        else if(y % i == 0){
            ll j = y / i;
            uoc.push_back(i);
            uoc.push_back(j);
        }
    }
    for(int i = 0; i < uoc.size(); ++i){
        for(int j = i; j < uoc.size(); ++j){
            int k = x - uoc[i] - uoc[j];
//            cout << uoc[i] << " " << uoc[j] << " " << k << "\n";
            if(k > 0 && y % k == 0){
                vector<ll> temp;
                temp.push_back(uoc[i]);
                temp.push_back(uoc[j]);
                temp.push_back(k);
                pot.push_back(temp);
            }
        }
    }
//    for(int i = 0; i < pot.size(); ++i){
//        cout << pot[i][0] << " " << pot[i][1] << " " << pot[i][2] << "\n";
//    }
    for(int i = 0; i < n; ++i){
        co[a[i]].first = true;
        co[a[i]].second.push_back(i);
        for(int j = 0; j < pot.size(); ++j){
            if(co[pot[j][0]].first && co[pot[j][1]].first && co[pot[j][2]].first){
                vector<vector<ll>> temp;
                for(int k = 0; k < 3; ++k){
                    temp.push_back(co[pot[j][k]].second);
                }
                vector<ll> res;
                for(int k = 0; k < 3; ++k){
                    if(co[pot[j][k]].second.size() == 0) break;
                    res.push_back(co[pot[j][k]].second.back());
                    co[pot[j][k]].second.pop_back();
                    if(k == 2){
                        sort(res.begin(), res.end());
                        for(int idx : res){
                            cout << a[idx] << " ";
                        }
                        return;
                    }
                }
                for(int k = 0; k < 3; ++k){
                    co[pot[j][k]].second = temp[k];
                }
            }
        }
    }
    cout << -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("THREENUMS.INP", "r", stdin);
    freopen("THREENUMS.OUT", "w", stdout);
    readData();
    threenums();
    return 0;
}
