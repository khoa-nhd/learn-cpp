#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

void fracnum(ll n){
    ull low = 1, high = 2000000005;
    ull duongCheo = 0;
    while(low <= high){
        ull half = (low + high) / 2LL;
        if((half * (half + 1LL)) / 2LL >= n){
            duongCheo = half;
            high = half - 1;
        } else{
            low = half + 1;
        }
    }

    ull i, j;
    ull posDiagonal;
    posDiagonal = n - (duongCheo*(duongCheo - 1))/2;
    if(duongCheo % 2 == 0){
        j = posDiagonal;
        i = duongCheo - posDiagonal + 1;
    } else{
        i = posDiagonal;
        j = duongCheo - posDiagonal + 1;
    }
    cout << i << "/" << j;
}

int main(){
    freopen("FRACNUM.INP", "r", stdin);
    freopen("FRACNUM.OUT", "w", stdout);
    ll n;
    cin >> n;
    fracnum(n);
    return 0;
}
