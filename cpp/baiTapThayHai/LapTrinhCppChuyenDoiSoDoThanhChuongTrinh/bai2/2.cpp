// Viết chương trình nhập vào 3 số thực dương a, b, c.
// Cho biết a,b,c có là 3 cạnh của 1 tam giác hay không?
// Nếu có hãy xuất ra màn hình thông báo đó là tam giác
// loại gì tron các loại sau: đều, cân, vuông, vuông cân, nhọn, tù.
#include <cstdio>
#include <iostream>
using namespace std;
bool tg(double a, double b, double c){
    if (a+b>c && a+c>b && b+c>a){
        return true;
    }
    return false;
}
bool deu(double a, double b, double c){
    if (a==b && a==c){
        return true;
    }
    return false;
}
bool vuong(double a, double b, double c){
    if (a*a+b*b==c*c || a*a+c*c==b*b || c*c+b*b==a*a){
        return true;
    }
    return false;
}
bool can(double a, double b, double c){
    if (a==b || a==c || b==c){
        return true;
    }
    return false;
}
bool nhon(double a, double b, double c){
    if (a*a+b*b>c*c && a*a+c*c>b*b && c*c+b*b>a*a){
        return true;
    }
    return false;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    double a, b, c;
    cin>>a>>b>>c;
    if (tg(a, b, c)) {
        if (deu(a, b, c)){
            cout<<"TAM GIAC DEU";
        } else if (can(a, b, c)){
            if (vuong(a, b, c)){
                cout<<"TAM GIAC VUONG CAN";
            }
            cout<<"TAM GIAC CAN";
        } else if (vuong(a, b, c)){
            cout<<"TAM GIAC VUONG";
        } else if (nhon(a, b, c)){
            cout<<"TAM GIAC NHON";
        } else {
            cout<<"TAM GIAC TU";
        }
    } else {
        cout<<"KHONG PHAI TAM GIAC";
    }
    return 0;
}
