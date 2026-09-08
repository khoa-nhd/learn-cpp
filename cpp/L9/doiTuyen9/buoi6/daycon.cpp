#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

bool prime[maxN] = {};
ll n, a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void sangNguyenTo(){
    for(int i = 2; i < maxN; ++i){
        prime[i] = true;
    }
    for(int i = 2; i * i < maxN; ++i){
        if(prime[i]){
            for(int j = i * i; j < maxN; j += i){
                prime[j] = false;
            }
        }
    }
}

ll daycon(){
    ll l = 0, r = 0, cnt = 0;
    ll minlen = LLONG_MAX;
    while(r < n){
        if(prime[a[r]]) cnt += 1;
        if(cnt == 2){
            while(!prime[a[l]]){
                l += 1;
            }
            cnt = 1;
            ll len = r - l + 1;
            minlen = min(minlen, len);
            l = r;
        }
        r += 1;
    }
    if(minlen = LLONG_MAX) return -1;
    return minlen;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    sangNguyenTo();
    readData();
    ll res;
    res = daycon();
    cout << res;
    return 0;
}
