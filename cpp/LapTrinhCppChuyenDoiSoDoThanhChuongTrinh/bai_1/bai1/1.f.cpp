// Cho số nguyên dương n, tính giá trị của biểu thức
// f) s = 1 + 1/(2+1/(3+...+1/n))

#include <iostream>
#include <cmath>
using namespace std;

double tinhGiaTri(int n)
{
    double s = 1 / n;
    int i = n - 1;
    while (i >= 2) {
        s = 1/(i + s);
        i = i - 1;
    }
    s = s + 1;
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
