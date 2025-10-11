// Tính có bao nhiêu thứ 6 ngày 13 trong hành tinh cyberplanet
// Mỗi tháng 30 ngày, mỗi tuần 7 ngày
// Ngày trong năm bắt đầu từ ngày thứ k, có n tháng
#include <iostream>
#include <cstdio>
using namespace std;
int friday(int n, int k){
    int i = (k+13) % 7, thang = 1, ngay;
    while( !(i == 6) ){
        i = (i+30) % 7;
        thang = thang + 1;
    }
    if (thang>n){
        ngay = 0;
    } else if (thang == n){
        ngay = 1;
    } else{
        ngay = (n-thang) / 7 + 1;
    }
    return ngay;
}
int main(){
    freopen("FRIDAY.INP", "r", stdin);
    freopen("FRIDAY.OUT", "w", stdout);
    int n, k, m;
    cin>>n>>k;
    m = friday(n, k);
    cout<<m;
    return 0;
}
