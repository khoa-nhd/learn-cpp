//Cho số nguyên dương n. Thiết kế thuật toán thực hiện
// h) Đếm số lượng ước dương của n
#include <iostream>
#include <cmath>
using namespace std;

int tinhGiaTri(int n)
{
    int soUocDuong = 0, i = 1, m = sqrt(n);
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

int main()
{
    int n;
    cin>>n;
    int m = tinhGiaTri(n);
    cout<<m;
    return 0;
}
