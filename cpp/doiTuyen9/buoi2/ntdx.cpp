#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

bool symprime[maxN] = {};

ll reverseN(ll n){
    ll res = 0;
    while(n > 0){
        res *= 10;
        res += n % 10;
        n /= 10;
    }
    return res;
}

ll mu10(ll n){
    ll res = 1;
    for(int i = 0; i < n; ++i){
        res *= 10;
    }
    return res;
}

bool checkSym(ll n){
    if(n < 10) return true;
    ll xet = n;
    ll sizeN = 0;
    while(xet > 0){
        xet /= 10;
        sizeN += 1;
    }
    ll first = 0, second = 0;
    ll power = mu10(sizeN / 2);
    second = reverseN(n % power);
    if(sizeN % 2 == 0){
        first = n / power;
    } else{
        first = n / (10 * power);
    }
    if(first == second){
        return true;
    }
    return false;
}

void sangNguyenToDoiXung(){
    for(int i = 2; i < maxN; ++i){
        symprime[i] = true;
    }
    for(int i = 2; i * i < maxN; ++i){
        if(symprime[i]){
            for(int j = i * i; j < maxN; j += i){
                symprime[j] = false;
            }
        }
    }
    for(int i = 0; i < maxN; ++i){
        if(symprime[i]){
            if(!checkSym(i)) symprime[i] = false;
        }
    }
}

int main(){
    sangNguyenToDoiXung();
    ll a, b;
    cin >> a >> b;
    ll res = 0;
    for(int i = a; i < b; ++i){
        if(symprime[i]) res += 1;
    }
    cout << res;
    return 0;
}
