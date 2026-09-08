// Viết chương trình nhập vào số nguyên n
// Cho biết tất cả các số hạnh phúc
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int tinhGiaTri(int n)
{
    int chuSo = 0;
    while (n>0) {
        n = n / 10;
        chuSo = chuSo + 1;
    }
    return chuSo;
}
int mu(int m) {
    int a = 1;
    for (int i = 0; i < m; ++i)
        a *= 10;
    return a;
}
int tachsodau(int n){
    int tachso = tinhGiaTri(n)/2, s = n/mu(tachso), tongsodau = 0, i = 0, sochuso = tinhGiaTri(n);
    while (i<=tachso){
        tongsodau = tongsodau + s%10;
        s = s / 10;
        i = i + 1;
    }
    return tongsodau;
}
int tachsocuoi(int n){
    int tachso = tinhGiaTri(n)/2, s = n%mu(tachso), tongsodau = 0, i = 0, sochuso = tinhGiaTri(n);
    while (i<=tachso){
        tongsodau = tongsodau + s%10;
        s = s / 10;
        i = i + 1;
    }
    return tongsodau;
}
void hnum(int n)
{
    int i = 1, digitnum;
    while (i <= n) {
        digitnum = tinhGiaTri(i);
        if (digitnum % 2 == 0){
            if (tachsodau(i) == tachsocuoi(i)){
                cout<<i<<"\n";
            }
        }
        i = i + 1;
    }
}
int main(){
    freopen("HNUM.INP", "r", stdin);
    freopen("HNUM.OUT", "w", stdout);
    int n;
    cin>>n;
    hnum(n);
    return 0;
}
