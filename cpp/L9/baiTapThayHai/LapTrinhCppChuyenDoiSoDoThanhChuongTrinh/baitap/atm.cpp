// Viết chương trình nhập vào số nguyên a, b, c, n là số tờ tiền 5, 10, 20 đồng, và số tiền cần rút
// Cho biết số các có thể trả tiền khác nhau.
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int atm(int a, int b, int c, int n)
{
    int s = 0, i = 0, j = 0;
    while (i <= c && i*20 <= n){
        while (j <= b && j + i*20 <= n && j*10 <= n){
            int k = n - i * 20 - j * 10;
            if (k >= 0 && k % 5 == 0 && k / 5 <= a) {
                s = s + 1;
            }
            j = j + 1;        }
        j = 0;
        i = i + 1;
    }
    return s;
}
int main(){
    freopen("ATM.INP", "r", stdin);
    freopen("ATM.OUT", "w", stdout);
    int a, b, c, n, m;
    cin>>a>>b>>c>>n;
    m = atm(a, b, c, n);
    cout<<m;
    return 0;
}
