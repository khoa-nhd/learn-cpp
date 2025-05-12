// Cho số nguyên dương n, tính giá trị của biểu thức
// c) 1 - 1/2! + ... + pow(-1, n+1)*1/n!

#include <iostream>
#include <cmath>
using namespace std;

double tinhGiaTri(int n)
{
    double s = 0;
    int i = 1;
    double giaiThua = 1;
    while (i <= n) {
        giaiThua = giaiThua*i;
        if (i % 2 == 0){
            s = s - 1 / giaiThua;
        } else {
            s = s + 1/giaiThua;
        }
        i = i + 1;
    }
    return s;
}

int main()
{
    int n;
    cin>>n;
    double m = tinhGiaTri(n);
    cout<<m;
    return 0;
}
