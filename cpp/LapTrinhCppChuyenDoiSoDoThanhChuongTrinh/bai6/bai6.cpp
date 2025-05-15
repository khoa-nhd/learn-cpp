// Viết chương trình nhập vào 4 số nguyên r1, c1, r2, c2 là bán kính và giá tiền của hai loại bánh.
// Cho biết loại bánh nào thì có lợi hơn theo nghĩa: cùng số tiền nhưng mua được nhiều bánh hơn.
#include <cstdio>
#include <iostream>
using namespace std;
void banh(int a, int b, int c, int d){
    if ((double)a/b > (double)c/d){
        cout<<"1";
    } else{
        cout<<"2";
    }
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    banh(a, b, c, d);
    return 0;
}

