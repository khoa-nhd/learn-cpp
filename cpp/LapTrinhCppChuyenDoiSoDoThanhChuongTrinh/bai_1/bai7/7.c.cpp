//Cho số nguyên dương n. Thiết kế thuật toán thực hiện
// c) Tính tổng chên lệch giữa hai chữ số liền kề nhau của n
#include <iostream>
#include <cmath>
using namespace std;

int tinhGiaTri(int n)
{
    int s = 0;
    int a = n%10;
    n = n/10;
    while (n>0) {
        s = s + abs(a - n%10);
        a = n%10;
        n = n/10;
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
