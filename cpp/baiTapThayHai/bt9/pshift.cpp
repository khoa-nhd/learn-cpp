#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 200005

ll n, a[maxN];
ll b[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        b[i] = a[i];
    }
}

ll lonHon(ll target){
    ll d = 0, c = n-1;
    ll res = -1;
    while(d <= c){
        ll half = (d + c) / 2;
        if(b[half] > target){
            res = half;
            c = half - 1;
        } else d = half + 1;
    }
    return res;
}

ll lonHonHoacBang(ll target){
    ll d = 0, c = n-1;
    ll res = -1;
    while(d <= c){
        ll half = (d + c) / 2;
        if(b[half] >= target){
            res = half;
            c = half - 1;
        } else d = half + 1;
    }
    return res;
}

ll pshift(){
    sort(b, b + n);
    ll minn = 0;
    ll curr = 0;
    ll res = 0;
    for(int i = 0; i < n-1; ++i){
        ll lh = lonHon(a[i]);
        if(lh != -1){
            lh = n - lh + 1;
        } else{
            lh = 0;
        }
        ll nh = lonHonHoacBang(a[i]) + 1;
        curr += lh;
        curr -= nh;
        if(curr < minn){
            minn = curr;
            res = i+1;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PSHIFT.INP", "r", stdin);
    freopen("PSHIFT.OUT", "w", stdout);
    readData();
    ll res;
    res = pshift();
    cout << res;
    return 0;
}
