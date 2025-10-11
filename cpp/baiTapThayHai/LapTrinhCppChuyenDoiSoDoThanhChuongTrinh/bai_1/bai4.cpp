// Dãy số nguyên {Fi} được định nghĩa như sau: F1 = 1
//                                             F2 = 1
//                                             Fn = Fn-1 + Fn-2, n>=3
//Cho số nguyên dương n. Thiết kế thuật toán tìm giá trị của Fn
#include <iostream>
#include <cmath>
using namespace std;

int tinhGiaTri(int n)
{
    int Fn = 1;
    int i = 3;
    int a = 1, b = 1;
    while (i <= n) {
        Fn = a + b;
        a = b;
        b = Fn;
        i = i + 1;
    }
    return Fn;
}

int main()
{
    int n;
    cin>>n;
    int m = tinhGiaTri(n);
    cout<<m;
    return 0;
}
