// Viết chương trình nhập vào 3 số thực a, b, r.
// Cho biết hình chữ nhật có che phủ hoàn toàn hình tròn không
#include <cstdio>
#include <iostream>
using namespace std;
void che(double a, double b, double r){
    if (a>=r*2 && b>=r*2){
        cout<<"YES";
    } else{
        cout<<"NO";
    }
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    double a, b, r;
    cin>>a>>b>>r;
    che(a, b, r);
    return 0;
}
