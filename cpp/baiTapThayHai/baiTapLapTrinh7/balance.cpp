#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, x, a[maxN];
ll idx;

void readData(){
    cin >> n >> x;
    for(int i = 0; i < n; ++i){
        ll temp;
        cin >> temp;
        if(temp > x) a[i] = 1;
        else if (temp < x) a[i] = -1;
        else{
            a[i] = 0;
            idx = i;
        }
    }
}

ll balance(){
    for(int i = 1; i < n; ++i){
        a[i] += a[i-1];
    }
    ll res = 0;
    unordered_map<ll, ll> m;
    m[0] += 1;
    for(int i = 0; i < n; ++i){
        if(i >= idx){
            res += m[a[i]];
        }
        if(i < idx) m[a[i]] += 1;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BALANCE.INP", "r", stdin);
    freopen("BALANCE.OUT", "w", stdout);
    readData();
    ll res;
    res = balance();
    cout << res;
    return 0;
}
