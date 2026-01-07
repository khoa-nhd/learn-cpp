#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double h, w;

double sqrcut(){
    if(h < w) swap(h, w);
    double th1, th2;
    th1 = min(h/3, w);
    th2 = min(h/2, w/2);
    return max(th1, th2);
}

int main(){
    freopen("SQRCUT.INP", "r", stdin);
    freopen("SQRCUT.OUT", "w", stdout);
    cin >> h >> w;
    double res;
    res = sqrcut();
    cout << fixed << setprecision(3);
    cout << res;
    return 0;
}
