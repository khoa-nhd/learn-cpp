// Viết chương trình nhập vào số nguyên n
// Cho biết các cặp số hữu nghị
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int tongUoc(int n){
    int s = 0, i = 2;
    int m = sqrt(n);
    while (i <= m){
        if (n % i == 0){
            s += i;
            int other = n / i;
            if (other != i) s += other;
        }
        i = i + 1;
    }
    return s;
}
void fnum(int n)
{
    int i = 2, a = 0, b = 0;
    while (i <= n){
        a = tongUoc(i);
        if (a > i && a <= n){
            b = tongUoc(a);
            if (i == b && b < n){
                cout<<i<<" "<<a<<"\n";
            }
        }
        i = i + 1;
    }
    if (n < 75){
        cout<<-1;
    }
}

int main(){
    freopen("FNUM.INP", "r", stdin);
    freopen("FNUM.OUT", "w", stdout);
    int n;
    cin>>n;
    fnum(n);
    return 0;
}

