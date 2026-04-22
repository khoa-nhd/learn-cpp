#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000
typedef long long ll;

ll m, n, k;
vector<ll> a;
vector<pair<ll, ll>> b;

void readData(){
    cin >> n >> m >> k;
    a.resize(n);
    b.resize(m);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < m; ++i){
        ll temp;
        cin >> temp;
        b[i].first = temp - k;
        b[i].second = temp + k;
    }
}

ll apartments(){
    ll result = 0;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, j = 0;
    while(i < n && j < m){
        if(a[i] >= b[j].first && a[i] <= b[j].second){
            i += 1;
            j += 1;
            result += 1;
        } else if(a[i] > b[j].second){
            j += 1;
        } else{
            i += 1;
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("APARTMENTS.INP", "r", stdin);
    freopen("APARTMENTS.OUT", "w", stdout);
    readData();
    ll m;
    m = apartments();
    cout << m;
    return 0;
}
