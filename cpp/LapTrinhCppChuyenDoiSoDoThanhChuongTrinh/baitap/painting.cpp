// Viết chương trình nhập vào số nguyên n là số ô cần sơn
// Cho biết số ô trắng và đen
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
long long demUoc(long long n)
{
    long long soUocDuong = 0, i = 1, m = sqrt(n);
    while (i<=m) {
        if (n%i == 0) {
            soUocDuong = soUocDuong + 2;
        }
        i = i + 1;
    }
    if (m*m == n) {
        soUocDuong = soUocDuong-1;
    }
    return soUocDuong;
}
int main(){
    freopen("PAINTING.INP", "r", stdin);
    freopen("PAINTING.OUT", "w", stdout);
    long long n, m;
    cin>>n;
    m = demUoc(n);
    cout<<n - m<<" "<<m;
    return 0;
}
