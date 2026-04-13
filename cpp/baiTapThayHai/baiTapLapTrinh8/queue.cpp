#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;

ll sol(){
    ll res = 0;
    while(n > m){
        n -= m;
        res += m;
        if(n < 2) break;
        n /= 2;
    }
    res += n;
    return res;
}

int main(){
    freopen("QUEUE.INP", "r", stdin);
    freopen("QUEUE.OUT", "w", stdout);
    cin >> n >> m;
    ll res;
    res = sol();
    cout << res;
    return 0;
}
