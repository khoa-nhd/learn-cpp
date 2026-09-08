// Dãy số nguyên {Fn} được định nghĩa như sau:
// Fn = n (F1 + F2 + ... + Fn-1)
// Biết rằng F1 = 1, hãy tính giá trị của Fn
#include <iostream>
#include <cmath>
using namespace std;

int tinhGiaTri(int n)
{
    int Fn = 1;
    int i = 2;
    int a = 1;
    while (i <= n) {
        Fn = a * i;
        a = a + Fn;
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
