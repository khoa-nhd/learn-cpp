// Mỗi vùng nhớ có kích thước 4KB
// Cho số nguyên dương n là số byte
// Cho biết kích thước theo KB mà tập tin chiếm
#include <iostream>
#include <cstdio>
using namespace std;
int ntfs(int n){
    int s = 0;
    s = n / 4096;
    s = s * 4;
    if (n%4096 > 0){
        s = s + 4;
    }
    return s;
}
int main(){
    freopen("NTFS.INP", "r", stdin);
    freopen("NTFS.OUT", "w", stdout);
    int n, m;
    cin>>n;
    m = ntfs(n);
    cout<<m;
    return 0;
}
