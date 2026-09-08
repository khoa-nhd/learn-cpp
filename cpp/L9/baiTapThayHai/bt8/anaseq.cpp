#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, m, a[maxN], b[maxN];
unordered_map<ll, ll> uma, umb;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    cin >> m;
    for(int i = 0; i < m; ++i){
        cin >> b[i];
    }
}

void anaseq(){
    if(m < n){
        cout << "NO";
        return;
    }
    ll diff = n;
    for(int i = 0; i < n; ++i){
        uma[a[i]] += 1;
    }
    for(int i = 0; i < n; ++i){
        if(umb[b[i]] < uma[b[i]]) diff -= 1;
        umb[b[i]] += 1;
    }
    ll res = -1;
    if(diff == 0){
        cout << "YES" << "\n";
        cout << 1;
        return;
    }
    for(int i = n; i < m; ++i){
        if(umb[b[i]] < uma[b[i]]) diff -= 1;
        umb[b[i]] += 1;
        if(umb[b[i-n]] <= uma[b[i-n]]) diff += 1;
        umb[b[i-n]] -= 1;
        if(diff == 0){
            cout << "YES" << "\n";
            cout << i-n+2;
            return;
        }
    }
    cout << "NO";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ANASEQ.INP", "r", stdin);
    freopen("ANASEQ.OUT", "w", stdout);
    readData();
    anaseq();
    return 0;
}
