// Cho các số nguyên dương n, k, p1, p2 là số lần đi, số vé bán sỉ, giá vé bán sỉ, giá vé bán lẻ
// Hãy tính chi phí tối thiểu để mua vé
#include <iostream>
#include <cstdio>
using namespace std;
long long tickets(long long n, long long k, long long p1, long long p2){
    long long a = p1*n, b = n/k*p2 + n%k*p1, c = p2*(n/k), s = 0;
    if (n%k != 0){
        c = c + p2;
    }
    if(a <= b && a <= c){
        s = a;
    } else if(b <= a && b <= c){
        s = b;
    } else{
        s = c;
    }
    return s;
}
int main(){
    freopen("TICKETS.INP", "r", stdin);
    freopen("TICKETS.OUT", "w", stdout);
    long long n, k, p1, p2, m;
    cin>>n>>k>>p1>>p2;
    m = tickets(n, k, p1, p2);
    cout<<m;
    return 0;
}
