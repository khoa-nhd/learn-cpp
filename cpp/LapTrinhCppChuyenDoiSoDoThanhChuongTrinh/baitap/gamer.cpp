// Viết chương trình nhập vào số nguyên n là level mà game thủ cần đạt
// Cho biết gamer cần tiêu diệt quái ở level bao nhiêu
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int level(int n){
    int i = 1, s = 0;
    while (s < n){
        s = s + i;
        i++;
    }
    return i-1;
}
int main(){
    freopen("GAMER.INP", "r", stdin);
    freopen("GAMER.OUT", "w", stdout);
    int n, m;
    cin>>n;
    m = level(n);
    cout<<m;
    return 0;
}
