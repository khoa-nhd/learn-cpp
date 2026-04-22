#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> curr;
ll n;

void output(){
    for(ll x : curr){
        cout << x << " ";
    }
    cout << "\n";
}

void analyse(ll prev, ll sum){
    if(sum == n){
        output();
        return;
    }
    for(int i = prev; i + sum <= n; ++i){
        curr.push_back(i);
        analyse(i, sum + i);
        curr.pop_back();
    }
}

int main(){
    freopen("ANALYSE.INP", "r", stdin);
    freopen("ANALYSE.OUT", "w", stdout);
    cin >> n;
    analyse(1, 0);
    return 0;
}
