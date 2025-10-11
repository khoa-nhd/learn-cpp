// Viết chương trình nhập vào số nguyên a, số thực b, số nguyên n. Là chiều cao ban đầu,
// chiêu cao cây tăng mỗi ngày và số ngày chăm sóc.
// Xuất chiều cao của câu làm tròn 3 chữ số thập phân
#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;
double mu(double a, int n){
    int i = 1;
    double s = 1;
    while (i <= n){
        s = s * a;
        i = i + 1;
    }
    return s;
}
double nuoi(int a, double b, int n){
    double s;
    b = b / 100;
    s = a * mu((1+b), n);
    return s;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a, n;
    double m, b;
    cin>>a>>b>>n;
    m = nuoi(a, b, n);
    cout<<fixed<<setprecision(3)<<m;
    return 0;
}
