#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll n, a[maxN], b[maxN];
bool numsA[maxN] = {};
bool numsB[maxN] = {};

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
}

ll maxgcd(){
    for(int i = 0; i < maxN; ++i){
        numsA[i] = false;
        numsB[i] = false;
    }
    for(int i = 0; i < n; ++i){
        numsA[a[i]] = true;
        numsB[b[i]] = true;
    }

    ll maxGcd = 1;
    for(int i = maxN; i > 0; --i){
        bool foundA = false;
        bool foundB = false;
        for(int j = 1; j*i < maxN; ++j){
            if(numsA[j*i]){
                foundA = true;
            }
            if(numsB[j*i]){
                foundB = true;
            }
        }
        if(foundA && foundB){
            maxGcd = i;
            break;
        }
    }

    ll maxA = LLONG_MIN;
    ll maxB = LLONG_MIN;
    for(int i = 0; i < n; ++i){
        if(a[i] % maxGcd == 0){
            maxA = max(maxA, a[i]);
        }
        if(b[i] % maxGcd == 0){
            maxB = max(maxB, b[i]);
        }
    }
    return maxA + maxB;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MAXGCD.INP", "r", stdin);
    freopen("MAXGCD.OUT", "w", stdout);
    readData();
    ll res;
    res = maxgcd();
    cout << res;
    return 0;
}
