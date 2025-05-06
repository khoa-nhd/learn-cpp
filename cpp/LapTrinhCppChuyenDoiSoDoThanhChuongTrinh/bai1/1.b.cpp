// Cho số nguyên dương n, tính giá trị của biểu thức
// b)1/2 + 2/3 + ... + n-1/n

#include <iostream>
#include <cmath>
using namespace std;

double tinhGiaTri(int n)
{
    double s = 0;
    int i = 2;
    while (i <= n) {
        s = s + (double)(i-1)/i;
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
