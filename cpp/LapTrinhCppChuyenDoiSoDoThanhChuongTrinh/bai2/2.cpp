// Viết chương trình nhập vào 3 số thực dương a, b, c.
// Cho biết a,b,c có là 3 cạnh của 1 tam giác hay không?
// Nếu có hãy xuất ra màn hình thông báo đó là tam giác
// loại gì tron các loại sau: đều, cân, vuông, vuông cân, nhọn, tù.
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
void xetTamGiac(double a, double b, double c) {
    if (a+b>c && a+c>b && b+c>a){
        if (a==b && a==c) {
            cout<<"TAM GIAC DEU";
        } else if (a==b || a==c || b==c && pow(a, 2)+pow(b, 2)==pow(c, 2) || pow(a, 2)+pow(c, 2)==pow(b, 2) || pow(c, 2)+pow(b, 2)==pow(a, 2)){
            cout<<"TAM GIAC VUONG CAN";
        } else if (a==b || a==c || b==c){
            cout<<"TAM GIAC CAN";
        } else if (pow(a, 2)+pow(b, 2)==pow(c, 2) || pow(a, 2)+pow(c, 2)==pow(b, 2) || pow(c, 2)+pow(b, 2)==pow(a, 2)){
            cout<<"TAM GIAC VUONG";
        } else if (pow(a, 2)+pow(b, 2)>pow(c, 2) && pow(a, 2)+pow(c, 2)>pow(b, 2) && pow(c, 2)+pow(b, 2)>pow(a, 2)){
            cout<<"TAM GIAC NHON";
        } else {
            cout<<"TAM GIAC TU";
        }
    } else{
        cout<<"KHONG PHAI TAM GIAC";
    }
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    double a, b, c;
    cin>>a>>b>>c;
    xetTamGiac(a, b, c);
    return 0;
}
