#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll pre[maxN] = {};
bool prime[maxN];

bool checkPalind(ll x){
    ll temp = x;
    ll y = 0;
    while(temp > 0){
        y *= 10;
        y += temp % 10;
        temp /= 10;
    }
    return x == y;
}

void sang(){
    for(int i = 2; i < maxN; ++i) prime[i] = true;
    for(int i = 2; i * i < maxN; ++i){
        if(prime[i]){
            for(int j = i*i; j < maxN; j += i){
                prime[j] = false;
            }
        }
    }
    for(int i = 0; i < maxN; ++i){
        if(prime[i] && checkPalind(i)){
            pre[i] = i;
        }
    }
    for(int i = 1; i < maxN; ++i){
        pre[i] += pre[i-1];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    sang();
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        ll l, r;
        cin >> l >> r;
        cout << pre[r] - pre[l-1] << "\n";
    }
    return 0;
}
