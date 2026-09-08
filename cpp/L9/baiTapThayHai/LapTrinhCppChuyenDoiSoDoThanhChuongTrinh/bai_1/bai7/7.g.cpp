//Cho số nguyên dương n. Thiết kế thuật toán thực hiện
// g) Kiểm tra các chữ số của n có thứ tự tăng dần từ trái sang phải hay không
// số nằm bên trái <= số nằm bên phải
#include <iostream>
#include <cmath>
using namespace std;

int tinhGiaTri(int n)
{
    int a = 10;
    while (n>0) {
        if (n%10 <= a) {
            a = n % 10;
            n = n / 10;
        } else{
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    int m = tinhGiaTri(n);
    cout<<m;
    return 0;
}
