// Có xe buýt và xe taxi giá a, b (a > b)
// Xe buýt chở được 50 người và xe taxi chở được 4 người
// Tính chi phí nhỏ nhất để vận chuyển n học sinh đi
#include <iostream>
#include <cstdio>
using namespace std;
void trans(int a, int b, int n){
    int mincost = 0, xmin = 0, ymin = 0, x = 0, y = 0, cost = 0, loop = (n+49)/50;
    while (x<=loop){
        if (n-50*x<=0){
            y = 0;
        } else{
            y = ((n - 50*x)+3)/4;
        }
        cost = x*a+y*b;
        if(mincost>cost||mincost == 0){
            mincost = cost;
            xmin = x;
            ymin = y;
        }
        x = x + 1;
    }
    cout<<xmin<<" "<<ymin;
}
int main(){
    freopen("TRANS.INP", "r", stdin);
    freopen("TRANS.OUT", "w", stdout);
    int a, b, n;
    cin>>n>>a>>b;
    trans(a, b, n);
    return 0;
}
