// Cho 3 số nguyên dương a, b, n. Tìm giá trị lớn nhất của biểu thức ax + by,
// trong đó (x, y) là nghiệm nguyên không âm của bất phương trình ax + by <= n
#include <iostream>
#include <cmath>
using namespace std;

int tinhGiaTri(int a,int b,int n)
{
    int x = 0, y = 0, i = 1, maxVal = 0;
    while (x <= double(n/a)) {
        y = (n-a*x)/b;
        if (a*x + b*y > maxVal){
            maxVal = a*x + b*y;
        }
        x = x + 1;
    }
    return maxVal;
}

int main()
{
    int a, b, n;
    cin>>a>>b>>n;
    int m = tinhGiaTri(a, b, n);
    cout<<m;
    return 0;
}
