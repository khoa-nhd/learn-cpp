#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ull lastnum(){
    ull result = 1;
    for(int i = 0; i < 60; ++i){
        result *= 2;
    }
    return result;
}

int inverseq(ll n){
    ll solanlat = 0;
    ull d = 1, c = lastnum();
    while(d <= c){
        ull half = (d+c)/2;
        if(n <= half){
            c = half - 1;
        } else{
            solanlat += 1;
            d = half + 1;
        }
    }
    return solanlat%2;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("INVERSEQ.INP", "r", stdin);
    freopen("INVERSEQ.OUT", "w", stdout);
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        ll n;
        cin >> n;
        int result = inverseq(n);
        cout << result << "\n";
    }
    return 0;
}
