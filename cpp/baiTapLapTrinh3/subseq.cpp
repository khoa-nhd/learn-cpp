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
    ll maxGlobal, maxCurrent = 0;
    ll startCurrent = 0, endCurrent = k-1;
    for(int i = 0; i < k; ++i){
        maxCurrent += a[i];
    }
    maxGlobal = maxCurrent;
    while (endCurrent < n){
        if(maxCurrent - a[startCurrent] > maxCurrent && endCurrent < n-1){
            ll temp = a[startCurrent], temp1 = a[endCurrent+1];
            maxCurrent = maxCurrent - a[startCurrent] + a[endCurrent+1];
            startCurrent += 1;
            endCurrent += 1;
        } else if(maxCurrent < 0 && endCurrent + k < n){
            maxCurrent = 0;
            for(int i = 0; i < k; ++i){
                maxCurrent += a[startCurrent+i+1];
            }
            startCurrent += 1;
            endCurrent = startCurrent + k - 1;
        } else{
            maxCurrent = maxCurrent + a[endCurrent+1];
            endCurrent += 1;
        }
        maxGlobal = max(maxCurrent, maxGlobal);
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
