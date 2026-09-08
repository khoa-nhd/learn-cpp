//Cho số nguyên dương n, tìm số nguyên dương x nhỏ nhất thỏa bất đẳng thức
//1 + sqrt(2) + sqrt(3) + ... + sqrt(x) >= n
#include <iostream>
#include <cmath>
using namespace std;

int tinhGiaTri(int n)
{
    double s = 0;
    int x = 0;
    while (s < n) {
        x = x + 1;
        s = s + sqrt(x);
    }
    return x;
}

int main()
{
    int n;
    cin>>n;
    int m = tinhGiaTri(n);
    cout<<m;
    return 0;
}
