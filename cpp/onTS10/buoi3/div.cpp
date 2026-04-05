#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

ll n, a[maxN];
ll sum = 0;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        sum += a[i];
    }
}

bool check(ll d){
    if(sum % d != 0) return false;
    ll t = sum / d;
    ll curr = 0;
    for(int i = 0; i < n; ++i){
        curr += a[i];
        if(curr == t){
            curr = 0;
        } else if(curr > t){
            return false;
        }
    }
    return true;
}

ll sol(){
    for(int i = n; i >= 2; --i){
        if(check(i)) return i;
    }
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    ll res;
    res = sol();
    cout << res;
    return 0;
}
