#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll n, m, a[maxN] = {}, b[maxN] = {};
vector<ll> c;
vector<ll> d;
vector<ll> dtemp;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
//        cout << a[i] << "\n";
    }
//    cout << "\n";
    cin >> m;
    for(int i = 0; i < m; ++i){
        cin >> b[i];
//        cout << b[i] << "\n";
    }
}

ll mySearch(ll target){
    ll l = 0;
    ll h = d.size() - 1;
    ll res = -1;
    while(l <= h){
        ll half = (l+h) / 2;
        if(d[half] >= target){
            res = half;
            h = half - 1;
        } else{
            l = half + 1;
        }
    }
    return res;
}

ll sol(){
//    c.push_back(a[0]);
//    for(int i = 1; i < n; ++i){
//        if(a[i] >= a[i-1]){
//            c.push_back(a[i]);
//        } else{
//            break;
//        }
//    }
//    dtemp.push_back(b[m-1]);
//    for(int i = m-2; i >= 0; --i){
//        if(b[i] <= b[i+1]){
//            dtemp.push_back(b[i]);
//        } else{
//            break;
//        }
//    }
//    for(int i = dtemp.size() - 1; i >= 0; --i){
//        d.push_back(dtemp[i]);
//    }

//    for(ll x : c){
//        cout << x << "\n";
//    }
//    cout << "\n";
//    cout << "\n";
//    for(ll x : d){
//        cout << x << "\n";
//    }
//    cout << "\n";

    // Prefix tăng dần của a
    c.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        if (a[i] >= a[i - 1])
            c.push_back(a[i]);
        else
            break;
    }

    // Suffix tăng dần của b
    d.push_back(b[m - 1]);
    for (int i = m - 2; i >= 0; i--) {
        if (b[i] <= b[i + 1])
            d.push_back(b[i]);
        else
            break;
    }
    reverse(d.begin(), d.end()); // để đúng thứ tự

    ll res = 0;
    for(int i = 0; i < c.size(); ++i){
        ll idx = mySearch(c[i]);
        if(idx != -1){
            res = max(res, (ll)(d.size() - idx) + i + 1);
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("MARBLE.INP", "r", stdin);
//    freopen("MARBLE.OUT", "w", stdout);
    readData();
    ll res;
    res = sol();
    cout << res;
    return 0;
}
