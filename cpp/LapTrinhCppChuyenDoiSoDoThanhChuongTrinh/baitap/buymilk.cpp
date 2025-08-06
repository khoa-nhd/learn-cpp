// Viết chương trình nhập vào số nguyên a, n, c là giá tiền a, mua n hộp thì được tặng 1 hộp và số tiền c
// Cho số hộp nhiều nhất có thể mua được
#include <cstdio>
#include <iostream>
using namespace std;
long long buymilk(long long a, long long n, long long c)
{
    long long sohop = 0, sohoptang = 0;
    sohop = c/a;
    sohoptang = sohop/n;
    sohop = sohop + sohoptang;
    return sohop;
}
int main(){
    freopen("BUYMILK.INP", "r", stdin);
    freopen("BUYMILK.OUT", "w", stdout);
    long long a, n, c, m;
    cin>>a>>n>>c;
    m = buymilk(a, n, c);
    cout<<m;
    return 0;
}
