// Cho số nguyên dương n, tính giá trị của biểu thức
// a) S = 1 + sqrt(2) + ... + sqrt(n)

#include <iostream>
#include <cmath>
using namespace std;

double tinhGiaTri(int n)
{
    double s = 0;
    int i = 1;
    while (i <= n) {
        s = s + sqrt(i);
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
