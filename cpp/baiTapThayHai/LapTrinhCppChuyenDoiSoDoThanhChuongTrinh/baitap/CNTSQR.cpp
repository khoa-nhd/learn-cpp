// Viết chương trình nhập vào số nguyên n, m là kích thước hình chữ nhật
// Cho biết số hình vuông có trong hình chữ nhật
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
long long demVuong(long long n, long long m)
{
    long long soVuong = 0;
    while (n>0 & m>0){
        soVuong = soVuong + n*m;
        n = n - 1;
        m = m - 1;
    }
    return soVuong;
}
int main(){
    freopen("CNTSQR.INP", "r", stdin);
    freopen("CNTSQR.OUT", "w", stdout);
    long long n, m, a;
    cin>>n>>m;
    a = demVuong(n, m);
    cout<<a;
    return 0;
}
