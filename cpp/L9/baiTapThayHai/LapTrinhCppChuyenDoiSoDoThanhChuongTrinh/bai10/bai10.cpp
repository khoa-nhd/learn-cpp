// Viết chương trình nhập vào số nguyên n
// Xuất ra các số nguyên tố theo thứ tự tăng dần
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
bool primeNumber(int n)
{
    if (n<=1){
        return false;
    }
    int i = 2, m = sqrt(n);
    while (i<=m) {
        if (n%i == 0) {
            return false;
        } else{
            i = i + 1;
        }
    }
    return true;
}
void lietKe(int n){
    int i = 0, a = 0;
    while (i<n){
        if (primeNumber(a)) {
            cout<<a<<"\n";
            i = i + 1;
        }
        a = a + 1;
    }
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a, n;
    cin>>n;
    lietKe(n);
    return 0;
}
