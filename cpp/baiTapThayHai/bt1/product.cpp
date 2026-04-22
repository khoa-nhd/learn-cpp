// Viết chương trình nhập vào số nguyên r , l
// Cho biết số lượng các số nguyên trong đoạn r, l chia hết cho tích các chữ số của mình
#include <cstdio>
#include <iostream>
using namespace std;
int tich(int n){
    int s = 1;
    while (n > 0){
        s = s * (n%10);
        n = n / 10;
    }
    return s;
}
int product(int r, int l) {
    int s = 0, i = l;
    while (i <= r){
        if (tich(i) != 0){
            if (i % tich(i) == 0){
                s = s + 1;
            }
        }
    i = i + 1;
    }
    return s;
}
int main(){
    freopen("PRODUCT.INP", "r", stdin);
    freopen("PRODUCT.OUT", "w", stdout);
    int r, l;
    int m;
    cin>>l>>r;
    m = product(r, l);
    cout<<m;
    return 0;
}

