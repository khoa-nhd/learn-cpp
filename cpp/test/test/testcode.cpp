#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
vector<ll> v;

void chuyen(){
    n += 1;
    while(n > 0){
        v.push_back(n % 10);
        n /= 10;
    }
    reverse(v.begin(), v.end());
}

void ocd(){
    for(int i = 0; i < v.size(); ++i){
        if(v[i] > )
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("i.INP", "r", stdin);
    freopen("o.OUT", "w", stdout);
    cin >> n;
    chuyen();
    ocd();
    return 0;
}
