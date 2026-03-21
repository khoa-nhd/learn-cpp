#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll t;
vector<int> pf;
bool prime[maxN] = {};

void sang(){
    for(int i = 2; i < maxN; ++i) prime[i] = true;
    for(int i = 2; i * i < maxN; ++i){
        if(prime[i]){
            for(int j = i * i ; j < maxN; j += i){
                prime[j] = false;
            }
        }
    }
}

void phantich(ll x){
    ll i = 2;
    while(x > 1){
        while(prime[i] && x % i == 0){
            x /= i;
            pf.push_back(i);
        }
        i += 1;
    }
}

ll dao(ll x){
    ll res = 0;
    while(x > 0){
        res *= 10;
        res += x % 10;
        x /= 10;
    }
    return res;
}

ll nhap(ll a, ll b){
    b = dao(b);
    ll res = a;
    while(b > 0){
        res *= 10;
        res += b % 10;
        b /= 10;
    }
    return res;
}

bool cmp(ll a, ll b){
    return nhap(a, b) > nhap(b, a);
}

void sol(){
    phantich(t);
    sort(pf.begin(), pf.end(), cmp);
    for(ll x : pf) cout << x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CAU3_15.INP", "r", stdin);
    freopen("CAU3_15.OUT", "w", stdout);
    cin >> t;
    sang();
    sol();
    return 0;
}
