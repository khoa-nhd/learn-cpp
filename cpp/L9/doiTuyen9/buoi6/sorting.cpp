#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 2000005

ll n, a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void sorting(){
    vector<ll> chan;
    vector<ll> le;
    vector<ll> res;
    for(int i = 0; i < n; ++i){
        if(a[i] % 2 == 0) chan.push_back(a[i]);
        else le.push_back(a[i]);
    }
    sort(chan.begin(), chan.end());
    sort(le.begin(), le.end());
//    for(ll x : chan) cout << x << " ";
//    cout << "\n";
//    for(ll x : le) cout << x << " ";
//    cout << "\n";
    ll ic = 0, il = 0;
    while(ic < chan.size() && il < le.size()){
        res.push_back(chan[ic]);
        res.push_back(le[il]);
        ic += 1;
        il += 1;
    }
    if(ic == chan.size() && il < le.size()){
        while(il < le.size()){
            res.push_back(le[il]);
            il += 1;
        }
    }
    if(il == le.size() && ic < chan.size()){
        while(ic < chan.size()){
            res.push_back(chan[ic]);
            ic += 1;
        }
    }
    for(ll x : res) cout << x << " ";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    sorting();
    return 0;
}
