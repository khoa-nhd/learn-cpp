// Viết chương trình nhập vào số nguyên p, t, n là giá cước 1 phút, 1 block(6 giây) và thời gian gọi
// Xuất ra số tiền người cần phải trả
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
long long tien(int p, int t, int n){
    long long s = 0;
    s = n/60*p + ceil((double)(n%60)/6)*t;
    return s;
}
int main(){
    freopen("MOBILE.INP", "r", stdin);
    freopen("MOBILE.OUT", "w", stdout);
    int p, t, n;
    long long m;
    cin>>p>>t>>n;
    m = tien(p, t, n);
    cout<<m;
    return 0;
}
