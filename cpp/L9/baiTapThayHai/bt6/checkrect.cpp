#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> x;
vector<ll> y;

void readData(){
    for(int i = 0; i < 4; ++i){
        ll temp;
        cin >> temp;
        x.push_back(temp);
        cin >> temp;
        y.push_back(temp);
    }
}

ll checkrect(){
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    if(!(x[0] == x[1] && x[2] == x[3] && y[0] == y[1] && y[2] == y[3])){
        return -1;
    }
    ll canh1 = x[3] - x[0];
    ll canh2 = y[3] - y[0];
    if(canh1 != canh2) return -1;
    return canh1 * canh2;
}

int main(){
    freopen("CHECKRECT.INP", "r", stdin);
    freopen("CHECKRECT.OUT", "w", stdout);
    readData();
    ll res;
    res = checkrect();
    cout << res;
    return 0;
}
