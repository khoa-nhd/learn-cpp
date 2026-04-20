#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll k, p, a[maxN];
ll sum = 0;

void readData(){
    cin >> k >> p;
    for(int i = 0; i < k; ++i){
        cin >> a[i];
        sum += a[i];
    }
}

bool check(ll x){
    ll m = x + (p-1);
    m /= p;
    ll s = 0;
    for(int i = 0; i < k; ++i){
        s += min(a[i], m);
    }
    return s >= x;
}

ll trees(){
    ll d = 0, c = sum;
    ll res = -1;
    while(d <= c){
        ll half = (d + c) / 2;
        if(check(half)){
            res = half;
            d = half + 1;
        } else{
            c = half - 1;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TREES.INP", "r", stdin);
    freopen("TREES.OUT", "w", stdout);
    readData();
    ll res;
    res = trees();
    cout << res;
    return 0;
}
