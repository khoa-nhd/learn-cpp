// Viết chương trình nhập vào số nguyên n
// Cho biết số lớn nhất nhận được khi dịch phải n
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int tinhGiaTri(long long n)
{
    int chuSo = 0;
    while (n>0) {
        n = n / 10;
        chuSo = chuSo + 1;
    }
    return chuSo;
}
long long rshift(long long n)
{
    int chuSo = tinhGiaTri(n);
    long long current = n, maxVal = 0, i = 0;
    while (i <= chuSo - 1){
        if (current > maxVal){
            maxVal = current;
        }
        current = current%10*pow(10, tinhGiaTri(current) - 1) + current/10;
        i = i + 1;
    }
    return maxVal;
}
int main(){
    freopen("RSHIFT.INP", "r", stdin);
    freopen("RSHIFT.OUT", "w", stdout);
    long long n, m;
    cin>>n;
    m = rshift(n);
    cout<<m;
    return 0;
}
