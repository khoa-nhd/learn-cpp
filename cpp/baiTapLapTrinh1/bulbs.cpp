// Mỗi lần đi bật/tắt đèn thì nhấn các công tác chia hết cho lần k
// Cho biết bóng đèn thứ n sau n lần đi thì bật hay tắt
// Ban đầu tất cả bóng đền dều tắt
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
bool bulbs(long long n){
    bool s = false;
    int m = sqrt(n);
    if (m*m == n){
        s = true;
    }
    return s;
}
int main(){
    freopen("BULBS.INP", "r", stdin);
    freopen("BULBS.OUT", "w", stdout);
    long long n;
    cin>>n;
    if (bulbs(n)){
        cout<<"ON";
    } else{
        cout<<"OFF";
    }
    return 0;
}
