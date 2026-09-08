#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll n, a[maxN] = {}, k;

void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll dpairs(){
    unordered_map<ll, ll> val;
    for(int i = 0; i < n; ++i){
        val[a[i]] += 1;
    }
    ll res = 0;
    for(int i = 0; i < n; ++i){
        ll need = a[i] - k;
        if(val.find(need) != val.end()){
            res += val[need];
        }
    }
    if(k == 0){
        res -= n;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readData();
    ll res;
    if(k == 0){
        res = dpairs()/2;
    } else{
        res = dpairs();
    }
    cout << res;
    return 0;
}
