//Cho số nguyên dương n. Thiết kế thuật toán thực hiện
// d) Tìm giá trị chênh lêch lớn nhất giữa hai chữ số liền kề nhau của n
#include <iostream>
#include <cmath>
using namespace std;

int tinhGiaTri(int n)
{
    int diff = 0, maxDiff = 0;
    int a = n%10;
    n = n/10;
    while (n>0) {
        diff = abs(a - n%10);
        if (diff > maxDiff) {
            maxDiff = diff;
        }
        a = n%10;
        n = n/10;
    }
    return maxDiff;
}

int main()
{
    int n;
    cin>>n;
    int m = tinhGiaTri(n);
    cout<<m;
    return 0;
}
