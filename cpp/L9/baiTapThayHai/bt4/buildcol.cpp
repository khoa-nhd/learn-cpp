#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100000

ll n, m, a[maxN];
ll maxH = -1;
ll moi[maxN], maxLeft[maxN], maxRight[maxN];

void readData(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        maxH = max(maxH, a[i]);
    }
}

bool checkPossible(ll x){
    ll nuoc = 0;
    for(int i = 0; i < n; ++i){
        moi[i] = max(a[i], x);
    }

    maxLeft[0] = moi[0];
    for(int i = 1; i < n; ++i){
        maxLeft[i] = max(moi[i], maxLeft[i-1]);
    }
    maxRight[n-1] = moi[n-1];
    for(int i = n-2; i >= 0; --i){
        maxRight[i] = max(moi[i], maxRight[i+1]);
    }

    for(int i = 0; i < n; ++i){
        nuoc += min(maxLeft[i], maxRight[i]) - moi[i];
        if(nuoc >= m) return true;
    }
    return nuoc >= m;
}

ll buildcol(){
    ll low = 0, high = maxH;
    ll result = -1;
    while(low <= high){
        ll half = (low + high) / 2;
        if(checkPossible(half)){
            low = half + 1;
            result = half;
        } else{
            high = half - 1;
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BUILDCOL.INP", "r", stdin);
    freopen("BUILDCOL.OUT", "w", stdout);
    readData();
    ll result;
    result = buildcol();
    cout << result;
    return 0;
}
