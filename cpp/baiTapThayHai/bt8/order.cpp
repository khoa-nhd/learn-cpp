#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, m;
ll a[maxN];
set<ll> giam;

void readData(){
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    a[0] = LLONG_MIN;
    a[n+1] = LLONG_MAX;
}

void order(){
    for(int i = 1; i <= n; ++i){
        if(a[i] < a[i-1]) giam.insert(i);
    }
    for(int i = 0; i < m; ++i){
        char loai;
        cin >> loai;
        if(loai == '?'){
            if(giam.size() == 0) cout << "YES" << "\n";
            else cout << "NO" << "\n";
        } else{
            ll k, x;
            cin >> k >> x;
            a[k] = x;
            if(a[k] > a[k + 1]) giam.insert(k+1);
            else giam.erase(k+1);
            if(a[k-1] > a[k]) giam.insert(k);
            else giam.erase(k);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ORDER.INP", "r", stdin);
    freopen("ORDER.OUT", "w", stdout);
    readData();
    order();
    return 0;
}
