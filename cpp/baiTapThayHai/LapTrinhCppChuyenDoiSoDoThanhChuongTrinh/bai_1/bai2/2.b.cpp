// Cho số nguyên dương n và số thực x, tính giá trị các biểu thức
// b) s = pow(x, n-1) + pow(x, n-2)/2! + ... + x/(n-1)! + 1/n!
#include <iostream>
#include <cmath>
using namespace std;

double tinhGiaTri(int n, double x)
{
    double s = 0;
    int i = 1;
    double giaiThua = 1;
    while (i <= n) {
        giaiThua = giaiThua * i;
        s = s*x + 1/giaiThua;
        i = i + 1;
    }
    return s;
}

int main()
{
    int n;
    double x;
    cin>>n>>x;
    double m = tinhGiaTri(n, x);
    cout<<m;
    return 0;
}
