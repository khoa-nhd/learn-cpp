#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll m, n;
ll a[maxN];
ll sum = 0;

void readData(){
    cin >> m >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        sum += a[i];
    }
}

ll candies(){
    sort(a, a + n, greater<ll>());
    ll tru[maxN] = {};
    ll res = 0;
    for(int i = 0; i < n - 1; ++i){
        tru[0] -= (a[i] - a[i+1]);
        if(m >= (a[i] - a[i+1]) * (i + 1)){
            m -= (a[i] - a[i+1]) * (i + 1);
            tru[i+1] += (a[i] - a[i+1]);
        } else{
            ll d = m / (a[i] - a[i+1]);
            tru[d] += (a[i] - a[i+1]);
            tru[d+1] -= m - m * d;
            tru[d+2] += m - m * d;
            m = 0;
            break;
        }
    }
    if(m > 0){
        ll d = m / a[n-1]
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("i.INP", "r", stdin);
    freopen("o.OUT", "w", stdout);
    readData();

    return 0;
}
