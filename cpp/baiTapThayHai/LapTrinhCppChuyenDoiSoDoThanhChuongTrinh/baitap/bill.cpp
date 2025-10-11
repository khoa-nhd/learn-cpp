// Viết chương trình nhập vào số nguyên n là kW
// Cho biết tiền điện
#include <cstdio>
#include <iostream>
using namespace std;
long long bill(int n)
{
    long long s = 0;
    if (n <= 50){
        s = n * 14;
    } else if (n <= 100){
        s = 50*14 + (n - 50)*15;
    } else if (n <= 200){
        s = 50*14 + 50*15 + (n - 100)*16;
    } else if (n <= 300){
        s = 50*14 + 50*15 + 100*16 + (n - 200)*17;
    } else if (n <= 400){
        s = 50*14 + 50*15 + 100*16 + 100*17 + (n - 300)*18;
    } else {
        s = (long long)50*14 + (long long)50*15 + (long long)100*16 + (long long)100*17 + (long long)100*18 + (long long)(n - 400)*20;
    }
    return s;
}

int main(){
    freopen("BILL.INP", "r", stdin);
    freopen("BILL.OUT", "w", stdout);
    int n;
    long long m;
    cin>>n;
    m = bill(n);
    cout<<m;
    return 0;
}

