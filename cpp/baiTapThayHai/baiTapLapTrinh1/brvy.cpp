// Cho x, d, t, v đoạn xanh, đỏ, tím, vàng có chiều dài dx, dx, dt, dv
// Hãy chọn mỗi loại một số và xếp chúng lại với nhau để có hình chữ nhật có diện tích lớn nhất với thứ tự xanh đỏ tím vàng
#include <iostream>
#include <cstdio>
#include <numeric>
using namespace std;

long long gcd(long long x, long long y){
    long long m = 0;
    if (x == 0||y == 0){
        return 0;
    }
    while(y != 0){
        m = x;
        x = y;
        y = m % y;
    }
    return x;
}

long long lcm(long long x, long long y){
    long long m = gcd(x, y);
    if (m == 0){
        return 0;
    }
    return x * y / m;
}

long long longestLengthPossible(int x, int y, int dx, int dy){
    long long lowest = lcm(x, y), multiply;
    if(dx<dy){
        multiply = dx/lowest;
    } else{
        multiply = dy/lowest;
    }
    return lowest*multiply;
}

int main(){
    freopen("BRVY.INP", "r", stdin);
    freopen("BRVY.OUT", "w", stdout);
    int x, dx, d, dd, t, dt, v, dv;
    long long a, b;
    cin>>x>>dx;
    cin>>d>>dd;
    cin>>t>>dt;
    cin>>v>>dv;
    long long blue = x*dx, red = d*dd, purple = t*dt, yellow = v*dv;
    a = longestLengthPossible(dx, dt, blue, purple);
    b = longestLengthPossible(dd, dv, red, yellow);
    if (a == 0||b == 0){
        cout<<0<<"\n";
        cout<<0<<" "<<0<<" "<<0<<" "<<0;
    }else {
        cout<<a*b<<"\n";
        cout<<a/dx<<" "<<b/dd<<" "<<a/dt<<" "<<b/dv;
    }
    return 0;
}
