//Cho số nguyên dương n. Thiết kế thuật toán thực hiện
// k) Phân tích n thành tích các thừa số nguyên tố
#include <iostream>
#include <cmath>
using namespace std;

void tinhGiaTri(int n)
{
    int i = 2;
    int m = sqrt(n);
    while (i<=m) {
        if (n%i == 0){
            n = n / i;
            cout<<i<<" ";
        } else{
            i = i + 1;
        }
    }
    if (n>1){
        cout<<n;
    }
}

int main()
{
    int n;
    cin>>n;
    tinhGiaTri(n);
    return 0;
}

