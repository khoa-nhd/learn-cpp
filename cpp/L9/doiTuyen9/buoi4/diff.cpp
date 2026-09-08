#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll diff(){
    ll n, m, a[1005] = {};
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    sort(a, a + n);
    ll minSum = 0;
    ll maxSum = 0;
    for(int i = 0; i < n-m; ++i){
        minSum += a[i];
    }
    for(int i = n; i >= m; --i){
        maxSum += a[i];
    }
//    cout << maxSum << " " << minSum << " ";
    return maxSum - minSum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        ll res;
        res = diff();
        cout << res << "\n";
    }
    return 0;
}
