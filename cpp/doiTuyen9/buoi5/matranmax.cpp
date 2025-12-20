#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll m, n, m1, n1;
ll a[105][105];
ll prefixSum[105][105] = {};

void readData(){
    cin >> m >> n >> m1 >> n1;
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }
}

void calPrefixSum(){
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            prefixSum[i][j] = a[i][j] + prefixSum[i][j-1] + prefixSum[i-1][j] - prefixSum[i-1][j-1];
        }
    }
}

void matranmax(){
    ll maxx = LLONG_MIN;
    pair<ll, ll> maxidx;
    for(int i = 1; i <= m - m1 + 1; ++i){
        for(int j = 1; j <= n - n1 + 1; ++j){
            ll val = prefixSum[i+m1-1][j+n1-1] - prefixSum[i+m1-1][j-1] - prefixSum[i-1][j+n1-1] + prefixSum[i-1][j-1];
            if(val > maxx){
                maxx = val;
                maxidx.first = i;
                maxidx.second = j;
            }
        }
    }
    cout << maxx << "\n";
    cout << maxidx.first << " " << maxidx.second;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    calPrefixSum();
    matranmax();
    return 0;
}
