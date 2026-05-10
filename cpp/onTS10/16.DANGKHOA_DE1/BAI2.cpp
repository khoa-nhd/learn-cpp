#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

vector<ll> v;
ll k;
bool prime[maxN] = {};

void readData(){
    cin >> k;
    ll temp;
    while(cin >> temp){
        v.push_back(temp);
    }
}

void sang(){
    for(int i = 2; i < maxN; ++i) prime[i] = true;
    for(ll i = 2; i < maxN; ++i){
        if(prime[i]){
            for(ll j = i * i; j < maxN; j += i){
                prime[j] = false;
            }
        }
    }
}

void sol(){
    set<ll> s;
    vector<ll> res;
    for(int i = 0; i < v.size(); ++i){
        if(prime[v[i]]) s.insert(v[i]);
    }
    for(ll x : v) res.push_back(x);
    for(int i = 0; i < k; ++i) cout << res[i];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BAI2.INP", "r", stdin);
    freopen("BAI2.OUT", "w", stdout);
    sang();
    readData();
    sol();
    return 0;
}
