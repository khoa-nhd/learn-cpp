//Cho số nguyên dương n. Thiết kế thuật toán thực hiện
// b) Tìm số có các chữ số đảo ngược với các chữ số của n
#include <iostream>
#include <cmath>
using namespace std;

int tinhGiaTri(int n)
{
    int soDaoNguoc = 0;
    while (n>0) {
        soDaoNguoc = soDaoNguoc*10 + n%10;
        n = n / 10;
    }
    return soDaoNguoc;
}

int main()
{
    int n;
    cin>>n;
    int m = tinhGiaTri(n);
    cout<<m;
    return 0;
}
