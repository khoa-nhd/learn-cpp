#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll demso(ll a, ll b, ll c){
    ll result = 0;
    ll khoangcach = (b - a) + 1;
    ll chiahet = b/c - (a-1)/c;
    result = khoangcach - chiahet;
    return result;
}

int main(){
    ll a, b, c;
    cin >> a >> b >> c;
    ll m;
    m = demso(a, b, c);
    cout << m;
    return 0;
}
