#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

bool checkPalind(vector<ll> &v){
    ll i = 0, j = v.size() -1;
    while(i < j){
        if(v[i] != v[j]) return false;
        i += 1;
        j -= 1;
    }
    return true;
}

bool doi(ll he){
    vector<ll> v;
    ll x = n;
    while(x > 0){
        v.push_back(x%he);
        x /= he;
    }
//    cout << "\n";
//    for(int i = v.size() - 1; i >= 0; --i){
//        cout << v[i];
//    }
//    cout << "\n";
    return checkPalind(v);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PALINBASE.INP", "r", stdin);
    freopen("PALINBASE.OUT", "w", stdout);
    while(true){
        cin >> n;
        if(n == 0) break;
        vector<ll> res;
        for(int i = 2; i <= 16; ++i){
            if(doi(i)) res.push_back(i);
        }
        if(res.size() == 0) cout << "NO" << "\n";
        else{
            cout << "YES ";
            for(int i = 0; i < res.size(); ++i) cout << res[i] << " ";
            cout << "\n";
        }
    }
    return 0;
}
