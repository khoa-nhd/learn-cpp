#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000
typedef long long ll;

ll n, k, a[maxN];

void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll subseq(){
    ll maxGlobal = LLONG_MIN, maxCurrent = 0;
    ll startCurrent = 0, endCurrent = k-1;
    vector <ll> prefixSum(n+1, 0);
    for(int i = 1; i <= n; ++i){
        prefixSum[i] = prefixSum[i-1] + a[i-1];
    }
    ll minn = 0;
    int j = 1;
    for(int i = k + 1; i <= n; ++i){
        minn = min(minn, prefixSum[j]);
        maxCurrent = prefixSum[i] - minn;
        maxGlobal = max(maxGlobal, maxCurrent);
        j++;
    }
    return maxGlobal;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SUBSEQ.INP", "r", stdin);
    freopen("SUBSEQ.OUT", "w", stdout);
    readData();
    ll m;
    m = subseq();
    cout << m;
    return 0;
}
