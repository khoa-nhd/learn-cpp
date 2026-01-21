#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
bool prime[1005] = {};
ll soMod = 1e9 + 9;

void sang(){
    for(int i = 2; i < 1000; ++i) prime[i] = true;
    for(int i = 2; i < 1000; ++i){
        if(prime[i]){
            for(int j = i*i; j < 1000; j += i){
                prime[j] = false;
            }
        }
    }
    for(int i = 99; i >= 0; --i) prime[i] = false;
}

bool check(ll x){
    if(x < 100) return false;
    if(x < 1000) return prime[x];
    while(x > 100){
        if(!prime[x % 1000]) return false;
        x /= 10;
    }
    return true;
}

void test(){
    ll cnt;
    cnt = 0;
    for(int i = 100000000; i < 1000000000; ++i){
        if(check(i)) cnt += 1;
    }
    cout << cnt << "\n";
}

ll prime3(){
    ll dp[10][10] = {};
    for(int i = 100; i < 1000; ++i){
        if(prime[i]){
            dp[i/10%10][i%10] += 1;
        }
    }
    for(int i = 3; i < n; ++i){
        ll nextdp[10][10] = {};
        for(int j = 0; j < 10; ++j){
            for(int k = 0; k < 10; ++k){
                for(int l = 0; l < 10; ++l){
                    if(prime[l*100 + j*10 + k]){
                        nextdp[j][k] += dp[l][j] % soMod;
                        nextdp[j][k] %= soMod;
                    }
                }
            }
        }
        for(int i = 0; i < 10; ++i){
            for(int j = 0; j < 10; ++j){
                dp[i][j] = nextdp[i][j];
            }
        }
    }
    ll res = 0;
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            res += dp[i][j];
            res %= soMod;
        }
    }
    return res;
}

int main(){
    freopen("PRIME3.INP", "r", stdin);
    freopen("PRIME3.OUT", "w", stdout);
    ll res;
    sang();
//    test();
    cin >> n;
    res = prime3();
    cout << res;
    return 0;
}
