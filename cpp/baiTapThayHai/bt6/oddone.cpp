#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, a[maxN];
ll preGcd[maxN], sufGcd[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll oddOne(){
    if(n == 1) return a[0] + 1;
    preGcd[0] = a[0];
    for(int i = 1; i < n; ++i){
        preGcd[i] = __gcd(a[i], preGcd[i-1]);
    }
    sufGcd[n-1] = a[n-1];
    for(int i = n-2; i >= 0; --i){
        sufGcd[i] = __gcd(a[i], sufGcd[i+1]);
    }

    if(a[0] % sufGcd[1] != 0){
        return sufGcd[1];
    }
    if(a[n-1] % preGcd[n-2] != 0){
        return preGcd[n-2];
    }
    for(int i = 1; i < n-1; ++i){
        ll g = __gcd(preGcd[i-1], sufGcd[i+1]);
        if(a[i] % g != 0){
            return g;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ODDONE.INP", "r", stdin);
    freopen("ODDONE.OUT", "w", stdout);
    readData();
    ll res;
    res = oddOne();
    cout << res;
    return 0;
}
