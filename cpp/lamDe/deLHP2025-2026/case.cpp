#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll x;

void sol(){
    ull d = 1;
    ull c = 2e9;
    ull hang;
    while(d <= c){
        ull half = (d+c)/2;
        ull val = ((half + 1) * half) / 2;
        if(val >= x){
            c = half - 1;
            hang = half;
        } else{
            d = half + 1;
        }
    }

    ull cot = x - (((hang - 1) * hang) / 2);
    cout << hang << " " << cot;
}

int main(){
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    cin >> x;
    sol();
    return 0;
}
