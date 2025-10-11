// Hãy tiềm số nguyên dương m nhỏ nhất sao cho tích của các chữa số của m đúng bằng n
#include <cstdio>
#include <iostream>
using namespace std;
int demChuSo(long long n) {
    int i = 0;
    while (n>0){
        n = n / (long long)10;
        i = i + 1;
    }
    return i;
}
long long reverseNum(long long n){
    int chuSo = demChuSo(n), i = 1, m = n;
    long long result = 0;
    while (i <= chuSo){
        result = result*10 + n%10;
        n = n / 10;
        i = i + 1;
    }
    return result;
}
long long prodig(int n){
    if (n == 0){return 10;}
    if (n == 1){return 1;}
    int i = 9, m = n;
    long long result = 0;
    while (n > 1){
        i = 9;
        while (i <= 9 && i >= 2) {
            if (n % i == 0){
                n = n / i;
                result = result*10 + (long long)i;
                break;
            }
            i = i - 1;
        }
        if (n == m){
            result = 0;
            break;
        }
        m = n;
    }
    if (result == 0){
        result = -1;
    } else{
        result = reverseNum(result);
    }
    return result;
}
int main(){
    freopen("PRODIG.INP", "r", stdin);
    freopen("PRODIG.OUT", "w", stdout);
    long long m;
    int n;
    cin>>n;
    m = prodig(n);
    cout<<m;
    return 0;
}
