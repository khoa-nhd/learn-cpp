//Cho số nguyên dương n. Thiết kế thuật toán thực hiện
// a) Đếm số chữ số của n
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

int main()
{
    int n;
    cin>>n;
    int m = tinhGiaTri(n);
    cout<<m;
    return 0;
}
