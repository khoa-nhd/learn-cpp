#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll k;
vector<ll> v[30];
char x[30] = {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

void prep(){
    for(int i = 1; i <= k; ++i){
        for(int j = 1; j <= k; ++j){
            v[i].push_back(j);
        }
    }
}

void sol(){
    prep();
//    cout << v[1].size() << " ";
//    for(int i = 0; i < v[2].size(); ++i){
//        cout << v[2][i] << " ";
//    }
    int i = 1;
    string res;
    res.push_back('a');
    while(v[i].size() > 0){
        res.push_back(x[v[i].back()]);
        ll temp = i;
        i = v[i].back();
        v[temp].pop_back();
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("STRING.INP", "r", stdin);
    freopen("STRING.OUT", "w", stdout);
    cin >> k;
    sol();
    return 0;
}
