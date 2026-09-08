#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[10000];
bool taken[10000] = {};
ll num[4] = {};

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        num[a[i]] += 1;
    }
}

void sol(){
    ll m = num[1];
    m = min(m, num[2]);
    m = min(m, num[3]);
    cout << m << "\n";
    for(int i = 0; i < m; ++i){
        vector<ll> d;
        for(int j = 1; j <= 3; ++j){
            for(int k = 0; k < n; ++k){
                if(a[k] == j && !taken[k]){
                    taken[k] = true;
                    d.push_back(k);
                    break;
                }
            }
        }
        sort(d.rbegin(), d.rend());
        for(int i = 0; i < 3; ++i) cout << d[i] + 1 << " ";
        cout << "\n";
    }
}

int main(){
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    sol();
    return 0;
}
