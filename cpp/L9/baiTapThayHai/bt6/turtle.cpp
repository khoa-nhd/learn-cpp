#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a, b, c, d;
ll goc[4];
vector<ll> curr;
bool taken[4] = {};
ll res = LLONG_MIN;

void area(){
    if(curr[0] > curr[2] && curr[1] > curr[3]){
        res = max(res, min(curr[0], curr[2]) * min(curr[1], curr[3]));
    }
}

void turtle(){
    if(curr.size() == 4){
//        for(int i = 0; i < 4; ++i){
//            cout << curr[i] << " ";
//        }
//        cout << "\n";
        area();
        return;
    }
    for(int i = 0; i < 4; ++i){
        if(!taken[i]){
            curr.push_back(goc[i]);
            taken[i] = true;
            turtle();
            curr.pop_back();
            taken[i] = false;
        }
    }
}

int main(){
    freopen("TURTLE.INP", "r", stdin);
    freopen("TURTLE.OUT", "w", stdout);
    cin >> a >> b >> c >> d;
    goc[0] = a;
    goc[1] = b;
    goc[2] = c;
    goc[3] = d;
    turtle();
    cout << res;
    return 0;
}
