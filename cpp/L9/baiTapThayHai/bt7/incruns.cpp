#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 200005

ll n, a[maxN];
ll num = 1;
ll quay = 0;
ll first = 0, last;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    last = n - 1;
//    for(int i = 0; i < n; ++i){
//        cout << a[i] << " ";
//    }
//    cout << "\n";
    for(int i = 0; i < n-1; ++i){
        if(a[i] >= a[i+1]){
            num += 1;
        }
    }
}

void truyvan1(ll i, ll x){
    ll cur = (first + i - 1) % n;
    ll nxt = (cur + 1) % n;
    ll prv = (cur - 1 + n) % n;
    if(cur != last && a[cur] < a[nxt] && x >= a[nxt]) num += 1;
    if(cur != first && a[prv] < a[cur] && a[prv] >= x) num += 1;
    if(cur != last && a[cur] >= a[nxt] && x < a[nxt]) num -= 1;
    if(cur!= first && a[prv] >= a[cur] && a[prv] < x) num -= 1;
    a[cur] = x;
}

void truyvan2(ll z){
    ll l = (first + z - 1) % n;
    ll r = (l + 1) % n;
    if(a[last] >= a[first]) num += 1;
    if(a[l] >= a[r]) num -= 1;
    first = r;
    last = l;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("INCRUNS.INP", "r", stdin);
    freopen("INCRUNS.OUT", "w", stdout);
    readData();
    ll m;
    cin >> m;
    for(int i = 0; i < m; ++i){
        int loai;
        cin >> loai;
        if(loai == 1){
            int x, y;
            cin >> x >> y;
            truyvan1(x, y);
            cout << num << "\n";
        } else{
            int z;
            cin >> z;
            truyvan2(z%n);
            cout << num << "\n";
        }
    }
    return 0;
}
