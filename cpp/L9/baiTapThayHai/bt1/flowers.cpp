// Cho 3 số a, b, c là giá tiền bó hoa hồng và hoa lan và số tiền có
// Cho biết giá trị bó hoa mua được lớn nhất
#include <iostream>
#include <cstdio>
using namespace std;
int flowers(int a, int b, int c){
    int maxVal = c/a * a, i = 0, d = c/a, f;
    if (c%a == 0 || c%b == 0){
        return c;
    }
    while(i<=d){
        f = (c - a*i)/b * b + a*i;
        if (maxVal < f){
            maxVal = f;
        }
        if (maxVal == c){
            return c;
        }
         i = i + 1;
    }
    return maxVal;
}
int main(){
    freopen("FLOWERS.INP", "r", stdin);
    freopen("FLOWERS.OUT", "w", stdout);
    int a, b, c, m;
    cin>>a>>b>>c;
    m = flowers(a, b, c);
    cout<<m;
    return 0;
}
