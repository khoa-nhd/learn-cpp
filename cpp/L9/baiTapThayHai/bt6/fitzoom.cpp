#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll w1, h1, w2, h2;
ll pw, ph;
double tiLeAnh;
double tiLeWin;


ll lamTron(double n){
    ll temp = (ll)(n * 10) % 10;
    if(temp >= 5){
        return (ll)n + 1;
    } else{
        return (ll)n;
    }
}

int main(){
    freopen("FITZOOM.INP", "r", stdin);
    freopen("FITZOOM.OUT", "w", stdout);
    cin >> w1 >> h1 >> w2 >> h2;
    tiLeAnh = (double)w1/(double)h1;
    tiLeWin = (double)w2/(double)h2;

    if(tiLeAnh > tiLeWin){
        pw = w2;
        double temp =  (double)h1 * (double)pw / (double)w1;
        ph = lamTron(temp);
    } else{
        ph = h2;
        double temp = (double)w1 * (double)ph / (double)h1;
        pw = lamTron(temp);
    }
    if(pw == 0) pw = 1;
    if(ph == 0) ph = 1;
    cout << pw << " " << ph;
    return 0;
}
