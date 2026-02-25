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

void lucky(){
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
        if(k - prefixMu[num-1] > (prefixMu[num] - prefixMu[num-1]) / 2){
            res.push_back(7);
            k -= mu2[num];
        } else{
            res.push_back(4);
            k -= mu2[num-1];
        }
        num -= 1;
    }
    for(int x : res) cout << x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("LUCKY.INP", "r", stdin);
    freopen("LUCKY.OUT", "w", stdout);
    cin >> k;
    gen();
    lucky();
    return 0;
}
