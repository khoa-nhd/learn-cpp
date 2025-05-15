// Viết chương trình nhập vào 4 số nguyên a1, b1, a2, b2.
// Cho biết hình chữ nhật có che phủ hoàn toàn hình hình chữ nhật khác không
#include <cstdio>
#include <iostream>
using namespace std;
void che(int a, int b, int c, int d){
    if ((a>=c && b>=d) || (a>=d && b>=c)){
        cout<<"YES";
    } else{
        cout<<"NO";
    }
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    che(a, b, c, d);
    return 0;
}
