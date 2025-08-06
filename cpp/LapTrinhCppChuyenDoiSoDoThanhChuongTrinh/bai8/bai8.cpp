// Viết chương trình nhập vào số nguyên a, n là số tế bào ban đầu và số tế bào cần.
// Xuất số ngày nuôi cấy tối thiểu
#include <cstdio>
#include <iostream>
using namespace std;
int nuoi(int a, int n){
    int i = 0;
    while (a < n){
        a = a * 2;
        i = i + 1;
    }
    return i;
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a, n, m;
    cin>>a>>n;
    m = nuoi(a, n);
    cout<<m;
    return 0;
}
