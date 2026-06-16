#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 200005

ll n, k, a[maxN];

void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

bool sol(){
    sort(a, a + n, greater<>());
    unordered_map<ll, ll> um;
    vector<ll> v;
    for(int i = 0; i < n; ++i){
        um[a[i]] += 1;
        if(i == 0 || a[i] != a[i-1]) v.push_back(a[i]);
    }
    ll curr = 0;
    v.push_back(-1e18);
    int so = v.size();
    if(um[v[0]] % 2 == 0) return true;
    for(int i = 0; i < so-1; ++i){
        if(v[i] - v[i+1] > k && um[v[i]] % 2 == 0) return true;
        if(v[i] - v[i+1] <= k) return true;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        readData();
        if(sol()) cout << "YES";
        else cout << "NO";
        cout << "\n";
    }
    return 0;
}
