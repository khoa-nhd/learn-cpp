#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll n, a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll alltri(){
    sort(a, a + n);
    ll maxx = a[0] + a[1];
    ll minn = a[n-1] - a[0];
    ll res = maxx - minn - 1;
    if(res < 0) return 0;
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ALLTRI.INP", "r", stdin);
    freopen("ALLTRI.OUT", "w", stdout);
    readData();
    ll res;
    res = alltri();
    cout << res;
    return 0;
}
