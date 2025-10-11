//Cho số nguyên dương n. Thiết kế thuật toán thực hiện
// f) Số đối xứng là số khi viết các chứ số của nó theo thứ tự
// ngược lại thì giá trị không bị thay đổi. Ví dụ 11, 121, 1221, ...
// là các số đối xứng. Kiểm tra n có phải là số đối xứng.
#include <iostream>
#include <cmath>
using namespace std;

int tinhGiaTri(int n)
{
    int soDaoNguoc = 0, soBanDau = n;
    while (n>0) {
        soDaoNguoc = soDaoNguoc*10 + n%10;
        n = n / 10;
    }
    return (soBanDau == soDaoNguoc);
}

int main()
{
    int n;
    cin>>n;
    int m = tinhGiaTri(n);
    cout<<m;
    return 0;
}
