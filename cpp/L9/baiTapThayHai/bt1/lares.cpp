#include <iostream>
#include <cstdio>
using namespace std;
int lares(int m, int n, int k){
    int nhom, le, thieu;
    nhom = min(m/2, n);
    le = m + n - 3*nhom;
    thieu = k - le;
    if (le<k){
        nhom = nhom - ((thieu-1)/3 + 1);
    }
    return nhom;
}
int main(){
    freopen("LARES.INP", "r", stdin);
    freopen("LARES.OUT", "w", stdout);
    int n, k, m, result;
    cin>>m>>n>>k;
    result = lares(m, n, k);
    cout<<result;
    return 0;
}
