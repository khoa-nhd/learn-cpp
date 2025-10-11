// Viết chương trình nhập vào số nguyên n, k là số nắp chai có và số nắp chai sẽ đổi được 1 chai
// Cho biết số chai có thể uống miễn phí
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int promotion(int n, int k)
{
    int soNapDoi, soNapCo;
    soNapDoi = n / k;
    soNapCo = n - k*soNapDoi + soNapDoi;
    while (soNapCo >=k){
        int a = soNapCo / k;
        soNapCo = soNapCo - a*k;
        soNapDoi = soNapDoi + a;
        soNapCo = soNapCo + a;
    }
    return soNapDoi;
}
int main(){
    freopen("PROMOTION.INP", "r", stdin);
    freopen("PROMOTION.OUT", "w", stdout);
    int n, k, m;
    cin>>n>>k;
    m = promotion(n, k);
    cout<<m;
    return 0;
}
