#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("BRICKS.INP", "r", stdin);
    freopen("BRICKS.OUT", "w", stdout);
    long long g, y;
    long long m, n;
    cin >> g >> y;
    double b = (g+4)/2.0;
    double c = g + y;
    double delta = b*b - 4*c;
    long long sqrtd = sqrtl(delta);
    m = (b + sqrtd) / 2;
    n = (g + y) / m;
    cout << m << " " << n;
    return 0;
}
