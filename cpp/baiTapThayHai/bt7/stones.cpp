#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll n, a[1005];
bool prime[maxN] = {};
ll f[2005][2005] = {};
vector<ll> v;

void sangNguyenTo(){
    for(int i = 2; i < maxN; ++i) prime[i] = true;
    for(int i = 2; i * i < maxN; ++i){
        if(prime[i]){
            for(int j = i * i; j < maxN; j += i){
                prime[j] = false;
            }
        }
    }
}

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        ll temp;
        cin >> temp;
        if(temp < 2){
            a[i] = 0;
        } else if(prime[temp]){
            a[i] = 1;
        } else{
            a[i] = 0;
        }
    }
    for(int i = 0; i < n; ++i) v.push_back(a[i]);
    for(int i = 0; i < n; ++i) v.push_back(a[i]);
}

ll stones(){
    ll res = 0;
    for(int i = 0; i < 2*n; ++i) f[i][i] = v[i];
    for(int l = 2; l <= n; ++l){
        for(int i = 0; i < 2*n; ++i){
            ll j = i + l - 1;
            if(j < 2*n-1){
                f[i][j] = max(f[i][i] - f[i+1][j], f[j][j] - f[i][j-1]);
            }
        }
    }
    for(int i = 0; i < n; ++i){
        if(f[i][i] > f[i+1][i+n-1]){
            res += 1;
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("STONES.INP", "r", stdin);
    freopen("STONES.OUT", "w", stdout);
    sangNguyenTo();
    readData();
    ll res;
    res = stones();
    cout << res;
    return 0;
}
