// Cho kích thước hình chữ nhật m x n
// Hãy cho biết số cột chống giữ xe ít nhất có thể
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    freopen("PARKING.INP", "r", stdin);
    freopen("PARKING.OUT", "w", stdout);
    long long n, m;
    cin>>n>>m;
    cout<<((n+1)/2)*((m+1)/2);
    return 0;
}
