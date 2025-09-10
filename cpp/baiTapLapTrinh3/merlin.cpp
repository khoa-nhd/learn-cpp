#include <bits/stdc++.h>
using namespace std;
#define maxN 100005
typedef long long ll;

ll n, a[maxN], maxx = -1;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if(a[i] > maxx){
            maxx = a[i];
        }
    }
}

ll dem(int d, int c, ll target){
    ll result;
    while(d <= c){
        ll half = (d+c)/2;
        if(a[half] > target){
            result = half;
            c = half-1;
        } else{
            d = half+1;
        }
    }
    return result;
}

ll merlin(){
    ll tong = 0;
    for(int i = 0; i < n; ++i){
        tong += a[i];
    }
    vector<ll> uoc;
    ll squareroot = sqrt(tong);
    for(int i = 1; i <= squareroot; ++i){
        if(tong % i == 0){
            uoc.push_back(i);
            uoc.push_back(tong/i);
        }
    }
    sort(uoc.begin(), uoc.end());
    sort(a, a+n);
    for(int i = (int)uoc.size()-1; i >= 0; --i){
        ll target = tong/uoc[i];
        ll demm = dem(0, n-1, target);
        if(target >= maxx && uoc[i] <= n && demm >= uoc[i]){
            return n - uoc[i];
        }
    }
    return n-1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MERLIN.INP", "r", stdin);
    freopen("MERLIN.OUT", "w", stdout);
    readData();
    ll m;
    m = merlin();
    cout << m;
    return 0;
}
