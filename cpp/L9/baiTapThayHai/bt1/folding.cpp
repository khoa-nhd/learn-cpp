//Cho kích thước mảnh giấy W x H
// Tính số lần gấp tối thiểu để biến thành mảnh giấy kích thước w x h
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
double folding(int to, int from){
    double result = 0;
    if (to>from) {
        return INFINITY;
    }
    if(to < from){
        while(from > to){
            from = (from + 1) / 2;
            result = result + 1;
        }
    }
    return result;
}
int main(){
    freopen("FOLDING.INP", "r", stdin);
    freopen("FOLDING.OUT", "w", stdout);
    int w = 2, h = 2, W = 7, H = 2;
    cin >> W >> H >> w >> h;
    double m1 = folding(w, W);
    double m2 = folding(h, H);
    double m3 = folding(h, W;
    double m4 = folding(w, H);
    double kq1 = m1 + m2;
    double kq2 = m3 + m4;
    double ans = min(kq1, kq2);
    if(ans == INFINITY){
        cout<<-1;
    } else{
        cout<<ans;
    }
    return 0;
}

