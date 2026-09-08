#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

ll t, n, a[maxN] = {};

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll productofsums(){
    ll sum1 = 0, sum2 = 0;
    ll half = n/2;
    for(int i = 0; i < half; ++i){
        sum1 += a[i];
    }
    for(int i = half; i < n; ++i){
        sum2 += a[i];
    }
    return sum1*sum2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for(int i = 0; i < t; ++i){
        readData();
        ll res;
        res = productofsums();
        cout << res << "\n";
    }
    return 0;
}
