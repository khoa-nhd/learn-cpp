#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("WEIGHTS.INP", "r", stdin);
    freopen("WEIGHTS.OUT", "w", stdout);
    cin >> n;
    vector<ll> tpcb;
    while(n > 0){
        ll r = n % 3;
        ll q = n / 3;
        if(r == 0){
            tpcb.push_back(0);
        } else if(r == 1){
            tpcb.push_back(1);
        } else{
            tpcb.push_back(-1);
            q += 1;
        }
        n = q;
    }
//    for(ll x : tpcb) cout << x << " ";
//    cout << "\n";
    for(int i = 0; i < tpcb.size(); ++i){
        if(tpcb[i] == 1) cout << i << " ";
    }
    cout << "\n";
    for(int i = 0; i < tpcb.size(); ++i){
        if(tpcb[i] == -1) cout << i << " ";
    }
    return 0;
}
