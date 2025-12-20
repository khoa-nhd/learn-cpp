#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 2000005

ll x[maxN], y[maxN];
pair<ll, ll> a[maxN];
ll m, n, k;

void readData(){
    cin >> m >> n >> k;
    for(int i = 0; i < 4*k; ++i){
        cin >> x[i] >> y[i];
        a[i].first = x[i];
        a[i].second = y[i];
    }
}

void sol(){
    nth_element(x, x + 2*k, x + 4*k);
    nth_element(x, x + 2*k - 1, x + 4*k);
    nth_element(y, y + 2*k, y + 4*k);
    nth_element(y, y + 2*k - 1, y + 4*k);
    ll half = 2*k;
    ll countTopLeft = 0;
    for(int i = 0; i < 4*k; ++i){
        if(a[i].first <= x[half-1] && a[i].second <= y[half-1]){
            countTopLeft += 1;
        }
    }
    if(countTopLeft == k){
        cout << (x[half] - x[half-1]) * (y[half] - y[half-1]);
    } else{
        cout << "0";
    }
//    return (x[half] - x[half-1]) * (y[half] - y[half-1]);
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("CAKE.INP", "r", stdin);
//    freopen("CAKE.OUT", "w", stdout);
    readData();
    sol();
    return 0;
}
