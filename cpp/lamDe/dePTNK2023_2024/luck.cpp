#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

ll cach1(){
    vector<ll> v;
    for(int i = 1; i <= n; ++i){
        v.push_back(i);
    }
    while(true){
        vector<ll> moi;
        for(int i = 0; i < v.size(); ++i){
            if((i+1) % 3 == 2){
                moi.push_back(v[i]);
            }
        }
        v = moi;
//        for(ll x : v){
//            cout << x << " ";
//        }
//        cout << "\n";
        if(moi.size() == 1) return moi[0];
    }
}

ll cach2(){
    vector<ll> maxVal;
    vector<ll> minVal;
    ll prev = 1;
    for(ll i = 1; i <= 19; ++i){
        ll val = 1;
        for(ll j = 0; j < i; ++j){
            val *= 3;
        }
        minVal.push_back(prev+1);
        prev += val;
        maxVal.push_back(prev);
    }
//    for(ll x : minVal) cout << x << " ";
//    cout << "\n";
//    for(ll x : maxVal) cout << x << " ";
    for(int i = 0; i < maxVal.size(); ++i){
        if(maxVal[i] >= n){
            return minVal[i];
        }
    }
}

int main(){
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    cin >> n;
    ll res;
    if(n <= 1000){
        res = cach1();
    } else{
        res = cach2();
    }
    cout << res;
    return 0;
}
