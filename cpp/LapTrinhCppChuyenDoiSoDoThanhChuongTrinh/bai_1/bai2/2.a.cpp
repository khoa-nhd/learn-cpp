// Cho số nguyên dương n và số thực x, tính giá trị các biểu thức
// a) s = x - pow(x, 2)/2! + ... + pow(-1, n+1) * xn/n!
#include <iostream>
#include <cmath>
using namespace std;

double tinhGiaTri(int n, double x)
{
    double s = 0;
    int i = 1;
    double giaiThua = 1;
    double luyThua = 1;
    while (i <= n) {
        giaiThua = giaiThua * i;
        luyThua = luyThua * x;
        if (i % 2 == 0) {
            s = s + luyThua/giaiThua;
        } else {
            s = s - luyThua/giaiThua;
        }
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
