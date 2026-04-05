#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m;
ll a[1005];

void readData(){
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        cin >> a[i];
    }
}

void sol(){
    sort(a, a + m, greater<ll>());
    ll profit = 0;
    ll cost = 0;
    for(int i = 0; i < min(m, n); ++i){
        if(profit < a[i] * (i + 1)){
            profit = a[i] * (i + 1);
            cost = a[i];
        }
    }
    cout << cost << " " << profit;
}

int main(){
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    sol();
    return 0;
}
