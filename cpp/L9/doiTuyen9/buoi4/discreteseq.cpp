#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll, ll> m;
ll n, a[10005];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void discrete(){
    for(int i = 0; i < n; ++i){
        m[a[i]] += 1;
    }
    for(auto x : m){
        cout << x.first << ":" << x.second << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    discrete();
    return 0;
}
