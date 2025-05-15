// Viết chương trình nhập vào 3 số nguyen a, b, c là số giá tiền của bánh và số tiền người có
// Xuất ra tất cả cách mua 2 loại bánh để số tiền phải trả đúng bằng c
#include <cstdio>
#include <iostream>
using namespace std;
void banh(int a, int b, int c){
    int i = 0, j= 0;
    while (i*a <= c){
        while (j*b + i*a <= c){
            if (i*a + j*b == c){
                cout<<i<<" "<<j<<"\n";
            }
            j = j + 1;
        }
        i = i + 1;
        j = 0;
    }
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a, b, c;
    cin>>a>>b>>c;
    banh(a, b, c);
    return 0;
}
