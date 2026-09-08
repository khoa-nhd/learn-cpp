#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 300005

bool prime[maxN] = {};

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

ll tongNguyenTo(ll n){
    ll res = 0;
    for(int i = 0; i < n; ++i){
        if(prime[i]){
            ll need = n - i;
            if(prime[need] && need > i){
                res += 1;
            }
        }
    }
    return res;
}

int main(){
    sangNguyenTo();
    ll n;
    cin >> n;
    ll res;
    res = tongNguyenTo(n);
    cout << res;
    return 0;
}
