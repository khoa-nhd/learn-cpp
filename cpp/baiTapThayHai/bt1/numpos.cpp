#include <iostream>
#include <cstdio>
using namespace std;
long long numpos(int k){
    long long position;
    if (k == 1){
        position = 1;
    } else if (k == 2){
        position = 2;
    } else{
        position = (long long)(k-2)*(long long)3;
    }
    return position;
}
int main(){
    freopen("NUMPOS.INP", "r", stdin);
    freopen("NUMPOS.OUT", "w", stdout);
    long long k, m;
    cin>>k;
    m = numpos(k);
    cout<<m;
    return 0;
}
