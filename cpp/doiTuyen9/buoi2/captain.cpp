#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool checkPrime(ll n){
    if(n < 2) return false;
    ll loop = sqrt(n);
    for(int i = 2; i <= loop; ++i){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

bool checkLeft(ll n){
    ll sizeN = 0;
    ll temp = n;
    while(temp > 0){
        temp /= 10;
        sizeN += 1;
    }

    ll tenPowSizeN = 1;
    for(int i = 0; i < sizeN; ++i){
        tenPowSizeN *= 10;
    }

    if(!checkPrime(n)) return false;
    ll mu10 = 10;
    while(mu10 < tenPowSizeN){
        if(!checkPrime(n%mu10)) return false;
        mu10 *= 10;
    }
    return true;
}

bool checkRight(ll n){
    while(n > 0){
        if(!checkPrime(n)) return false;
        n /= 10;
    }
    return true;
}

void checkStatus(ll n){
    bool l = checkLeft(n);
    bool r = checkRight(n);
    if(l && r) cout << "CENTRAL";
    else if(l) cout << "LEFT";
    else if(r) cout << "RIGHT";
    else cout << "FINED";
    cout << "\n";
}

int main(){
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        ll n;
        cin >> n;
        checkStatus(n);
    }
    return 0;
}
