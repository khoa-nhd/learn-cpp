#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100000

ll g, s, k, n;
ll val = 0;

void readData(){
    ll p, q, r;
    cin >> g >> s >> k;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> p >> q >> r;
        val += r + q*29 + p*17*29;
    }
}
void money(){
    ll myMoney = g*17*29 + s*29 + k;
    if(myMoney < val){
        cout << -1;
        return;
    }
    myMoney -= val;
    ll a, b, c;
    c = myMoney % 29;
    myMoney -= c;
    b = (myMoney / 29) % 17;
    myMoney -= b*29;
    a = myMoney/(29*17);

    cout << a << " " << b << " " << c;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MONEY.INP", "r", stdin);
    freopen("MONEY.OUT", "w", stdout);
    readData();
    money();
    return 0;
}
