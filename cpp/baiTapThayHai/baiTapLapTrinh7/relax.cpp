#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, a[maxN] = {};
ll pre[maxN] = {};

void readData(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    pre[0] = 0;
    for(int i = 1; i <= n; ++i){
        pre[i] = pre[i-1] + a[i];
    }
}

bool check(ll i, ll j){
    if((j-i+1) % 2 == 0) return false;
    ll trai, phai;
    trai = pre[j/2] - pre[i-1];
    phai = pre[j] - pre[j/2];
    if(phai == trai) return true;
    return false;
}

ll relax(){

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("i.INP", "r", stdin);
    freopen("o.OUT", "w", stdout);
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        readData();

    }
    return 0;
}
