#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll n, t, a[maxN];
ll pre[maxN] = {};

void readData(){
    cin >> n >> t;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
}

ll trash(){
    for(int i = 1; i <= n; ++i) pre[i] = pre[i-1] + a[i];
    ll res = 0;
    ll r = 0;
    for(int i = 0; i < )
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("i.INP", "r", stdin);
    freopen("o.OUT", "w", stdout);
    readData()

    return 0;
}
