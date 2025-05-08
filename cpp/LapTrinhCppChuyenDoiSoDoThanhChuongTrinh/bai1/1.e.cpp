// Cho số nguyên dương n, tính giá trị của biểu thức
// e) s = 1 * 3 * ... * n, nếu n lẻ
//    s = 2 * 4 * ... * n, nếu n chẵn

#include <iostream>
#include <cmath>
using namespace std;

int tinhGiaTri(int n)
{
    int s = 1;
    int i = n;
    while (i > 0) {
        s = s * i;
        i = i - 2;
    }
    return s;
}

int main()
{
    int n;
    cin>>n;
    int m = tinhGiaTri(n);
    cout<<m;
    return 0;
}
