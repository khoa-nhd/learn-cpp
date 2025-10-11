#include <bits/stdc++.h>
using namespace std;
#define maxN 1000005
typedef long long ll;

ll a[maxN] = {};

void idols(){
    ll n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        ll soIdols;
        cin >> soIdols;
        for(int j = 0; j < soIdols; ++j){
            ll idol;
            cin >> idol;
            a[idol] += 1;
        }
    }
    ll maxx = LLONG_MIN;
    for(int i = 0; i < maxN; ++i){
        maxx = max(maxx, a[i]);
    }
    for(int i = 0; i < maxN; ++i){
        if(a[i] == maxx){
            cout << i << " ";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("IDOLS.inp", "r", stdin);
    freopen("IDOLS.out", "w", stdout);
    idols();
    return 0;
}
