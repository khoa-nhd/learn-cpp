#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 200005

ll n, a[maxN];
ll res;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void nhap(ll l, ll r){
    vector<ll> v;
    ll half = (l + r) / 2;
    ll i = l, j = half + 1;
    while(i <= half && j <= r){
        if(a[i] <= a[j]){
            v.push_back(a[i]);
            i += 1;
        } else{
            v.push_back(a[j]);
            j += 1;
        }
    }
    while(i <= half) v.push_back(a[i]);
    while(j <= r) v.push_back(a[j]);
    i = 0;
    for(int k = l; k <= r; ++k){
        a[k] = v[i];
        i += 1;
    }
}

void split(ll l, ll r){
    if(l == r) return;
    ll half = (l + r) / 2;
    split(l, half);
    split(half + 1, r);
    nhap(l, r);
}

void sol(){
    split(0, n-1);
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("i.INP", "r", stdin);
    freopen("o.OUT", "w", stdout);
    readData();
    sol();
    cout << "\n";
    for(int i = 0; i < n; ++i){
        cout << a[i];
    }
    return 0;
}
