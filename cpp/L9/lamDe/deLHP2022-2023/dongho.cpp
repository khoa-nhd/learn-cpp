#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
int gio = 0, phut = 0;

void dongho(){
    double res = 0;
    res += (double)phut * 6;
    gio = 12 - (double)gio;
    res += (double)gio * 30;
    res -= 0.5 * (double)phut;
    if(res > 360) res -= 360;
    if(res > 180) res = 360 - res;
    cout << fixed << setprecision(3) << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("DONGHO.INP", "r", stdin);
//    freopen("DONGHO.OUT", "w", stdout);
    char colon;
    while(cin >> gio >> colon >> phut){
        if(gio == 0 && phut == 0) break;
        dongho();
    }
    return 0;
}
