#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, k, a[maxN];
ll maxleft[maxN] = {};
ll maxright[maxN] = {};
ll preSum[maxN] = {};

void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll prizes(){
    for(int i = 1; i <= n; ++i){
        preSum[i] = preSum[i-1] + a[i-1];
//        cout << preSum[i] << " ";
    }
//    cout << "\n";
    for(int i = k; i <= n; ++i){
        maxleft[i] = max(maxleft[i-1], preSum[i] - preSum[i - k]);
//        cout << maxleft[i] << " ";
    }
//    cout << "\n";
    maxright[n+1] = 0;
    for(int i = n-k+1; i >= 1; --i){
        maxright[i] = max(maxright[i+1], preSum[i+k-1] - preSum[i-1]);
    }
    for(int i = 0; i <= n - k + 1; ++i){
//        cout << maxright[i] << " ";
    }
//    cout << "\n";

    ll steve = LLONG_MAX;
    for(int i = 1; i <= n-k+1; ++i){
        ll temp = max(maxleft[i-1], maxright[i+k]);
        steve = min(steve, temp);
    }
    return steve;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PRIZES.INP", "r", stdin);
    freopen("PRIZES.OUT", "w", stdout);
    readData();
    ll result = prizes();
    cout << result;
    return 0;
}
