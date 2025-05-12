// Cho số nguyên dương n, tính giá trị của biểu thức
// d) sqrt(2+sqrt(2+...+sqrt(2))) (n dấu căn)

#include <iostream>
#include <cmath>
using namespace std;

double tinhGiaTri(int n)
{
    double s = 0;
    int i = 1;
    while (i <= n) {
        s = sqrt(2+s);
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
