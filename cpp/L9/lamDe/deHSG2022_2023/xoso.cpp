#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100000

ll k, n, a[maxN];
ll sonhan[maxN] = {};
ll motTy = 1000000000;

void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll nhanMod(ll a, ll b){
    ll result;
    a %= motTy + 7;
    b %= motTy + 7;
    result = a * b;
    result %= motTy + 7;
    return result;
}

ll xoso(){
    sort(a, a + n);
    ll nhan = 1;
    for(int i = k - 1; i < n; ++i){
        sonhan[i] = nhan;
        nhan += 1;
    }

    ll result = 0;
    for(int i = 0; i < n; ++i){
        result += nhanMod(a[i], sonhan[i]);
        result %= motTy + 7;
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("i.INP", "r", stdin);
    freopen("o.OUT", "w", stdout);
    readData();
    ll result;
    result = xoso();
    cout << result;
    return 0;
}
