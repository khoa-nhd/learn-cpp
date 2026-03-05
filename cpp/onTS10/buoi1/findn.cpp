#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll k;
ll mu2[100] = {};
ll prefixMu[100] = {};

void gen(){
    mu2[0] = 1;
    for(int i = 1; i < 65; ++i){
        mu2[i] = mu2[i-1] * 2;
        prefixMu[i] = prefixMu[i-1] + mu2[i];
    }
}

void findn(){
    ll temp = k;
    ll num = 1;
    ll mu = 2;
    while(k > mu){
        k -= mu;
        num += 1;
        mu *= 2;
    }
    k = temp;
    vector<ll> res;
    while(k > 0){
        if(k - prefixMu[num-1] > mu2[num]/2){
            res.push_back(7);
            k -= mu2[num];
        } else{
            res.push_back(4);
            k -= mu2[num-1];
        }
        num -= 1;
    }
    for(int x : res) cout << x;
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    gen();
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        cin >> k;
        findn();
    }
    return 0;
}
