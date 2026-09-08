#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000

int a[maxN] = {};

int gcd(int a, int b){
    if(a == 0){
        return b;
    }
    if(b == 0){
        return a;
    }
    while(b != 0){
        int m = a;
        a = b;
        b = m%b;
    }
    return a;
}

int maxdivi(int n){
    if(n == 2){
        return abs(a[0] - a[1]);
    }
    int g = gcd(abs(a[0] - a[1]), abs(a[1] - a[2]));
    for(int i = 3; i < n; ++i){
        g = gcd(g, abs(a[i-1] - a[i]));
    }
    return g;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MAXDIVI.INP", "r", stdin);
    freopen("MAXDIVI.OUT", "w", stdout);
    int i = 0;
    while(cin >> a[i]){
        i += 1;
    }
    int m = maxdivi(i);
    cout << m;
    return 0;
}
