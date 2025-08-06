// Cho các số nguyên dương w, d, m là thứ đầu năm và ngày d tháng m ở NKPlanet
// Thang 1 có 31 ngày, tháng 2 có 30 ngày, tháng 3 có 31 ngày
// Hãy cho biết ngày d tháng m là thứ mấy trong tuần
#include <iostream>
#include <cstdio>
using namespace std;
long long soNgay(int d, int m){
    long long odd = m / 2;
    long long even = (m - 1) - odd;
    long long total = odd * 31 + even * 30 + d;
    return total - 1;
}
long long calendar(int w, int d, int m){
    long long songay = soNgay(d, m);
    long long thu = songay % 7 + w;
    if(thu > 7){
        thu = thu - 7;
    }
    return thu;
}
int main(){
    freopen("CALENDAR.INP", "r", stdin);
    freopen("CALENDAR.OUT", "w", stdout);
    int w, d, m;
    long long result;
    cin>>w>>d>>m;
    result = calendar(w, d, m);
    cout<<result;
    return 0;
}
