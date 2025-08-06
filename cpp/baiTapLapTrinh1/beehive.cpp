// Nhập vào n lớp của tổ ong
// Ghi ra số lượng ô trong tổ
#include <iostream>
#include <cstdio>
using namespace std;
long long beehive(int n){
    return (long long)1 + (long long)6 * ((long long)n-(long long)1)*(long long)n/(long long)2;
}
int main(){
    freopen("BEEHIVE.INP", "r", stdin);
    freopen("BEEHIVE.OUT", "w", stdout);
    int n;
    long long m;
    cin>>n;
    m = beehive(n);
    cout<<m;
    return 0;
}
