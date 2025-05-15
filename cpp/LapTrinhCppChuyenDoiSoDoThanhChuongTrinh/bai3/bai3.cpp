// Viết chương trình nhập vào 2 số nguyên a, b là số tuổi của em và của anh.
// Cho biết bao nhiêu năm nữa hoặc cách đây bao nhiêu năm thì tuổi anh gấp đôi tuổi em
#include <cstdio>
#include <iostream>
using namespace std;
void tuoi(int a, int b){
    int tuoiEm = b-a;
    if (a<=tuoiEm){
        cout<<"sau "<<tuoiEm-a<<" nam nua";
    } else {
        cout<<"cach day "<<a-tuoiEm<<" nam";
    }
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a, b;
    cin>>a>>b;
    tuoi(a, b);
    return 0;
}
