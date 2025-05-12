//Cho số nguyên dương n. Thiết kế thuật toán thực hiện
// i) Kiểm tra n có phải là số nguyên tố hay không
#include <iostream>
#include <cmath>
using namespace std;

int tinhGiaTri(int n)
{
    if (n<=1){
        return false;
    }
    int i = 2, m = sqrt(n);
    while (i<=m) {
        if (n%i == 0) {
            return false;
        } else{
            i = i + 1;
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
