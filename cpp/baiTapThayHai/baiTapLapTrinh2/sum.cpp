// Cho số n
// Cho biết có bao nhiêu dãy số liên tiếp có tổng = n và xuất ra số đầu và số cuói của dãy số đó
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

void sum(long long n){
    long long  n2 = 2*n;
    int m = sqrt(n2), soLuong = 0;
    for(int i = 1; i<=m; ++i){
        if(n2 % i == 0){
            long long a = ((n2/i)-(long long)(i-1));
            long long b = ((n2/i)+(long long)(i-1));
            if(a%2 == 0 && b%2 == 0){
                soLuong += 1;
            }
        }
    }
    cout<<soLuong<<"\n";
    for(int i = m; i>0; --i){
        if(n2 % i == 0){
            long long a = ((n2/i)-(long long)(i-1));
            long long b = ((n2/i)+(long long)(i-1));
            if(a%2 == 0 && b%2 == 0){
                cout<<a/2<<" "<<b/2<<"\n";
            }
        }
    }
}

int main(){
    freopen("SUM.INP", "r", stdin);
    freopen("SUM.OUT", "w", stdout);
    long long n;
    cin>>n;
    sum(n);
    return 0;
}
