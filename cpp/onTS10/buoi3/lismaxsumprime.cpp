#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

bool prime[maxN];
ll n, a[maxN];

void sang(){
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
        cin >> a[i];
    }
}

void sol(){
    ll curr = 0;
    ll res = 0;
    if(prime[a[0]]){
        curr = a[0];
        res = a[0];
    }
    ll currLen = 1;
    ll maxLen = 1;
    for(int i = 1; i < n; ++i){
        if(a[i] > a[i-1]){
            if(prime[a[i]]){
                curr += a[i];
            }
            currLen += 1;
        } else{
            curr = 0;
            if(prime[a[i]]){
                curr = a[i];
            }
            currLen = 1;
        }
        if(currLen == maxLen){
            res = max(res, curr);
        } else if(currLen > maxLen){
            res = curr;
        }
        maxLen = max(maxLen, currLen);
    }
    cout << maxLen << " " << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    sang();
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        readData();
        sol();
    }
    return 0;
}
