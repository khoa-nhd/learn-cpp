//Cho số nguyên dương n. Thiết kế thuật toán thực hiện
// Tìm chữ số chẵn lớn nhất của n. Nếu n không chứa chữ số chẵn thì output -1
#include <iostream>
#include <cmath>
using namespace std;

int tinhGiaTri(int n)
{
    int maxEven = -1;
    while (n>0) {
        if (n%10%2 == 0) {
            if (n%10 > maxEven) {
                maxEven = n % 10;
            }
        }
        n = n/10;
    }
    return maxEven;
}

int main()
{
    int n;
    cin>>n;
    int m = tinhGiaTri(n);
    cout<<m;
    return 0;
}
