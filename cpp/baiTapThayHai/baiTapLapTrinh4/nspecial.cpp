#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll input;

ll sumdigit(ll n){
    ll result = 0;
    while(n > 0){
        result += n % 10;
        n /= 10;
    }
    return result;
}

ll sumPrimeFactors(ll n){
    ll result = 0;
    ll loop = sqrt(n);
    for(ll i = 2; i <= loop; ++i){
        while(n % i == 0){
            result += sumdigit(i);
            n /= i;
        }
    }
    if(result == 0) return -1;
    if(n > 1) result += sumdigit(n);
    return result;
}

ll nspecial(){
    ll i = input + 1;
    while(true){
        if(sumdigit(i) == sumPrimeFactors(i)){
            return i;
        } else{
            i += 1;
        }
    }
}

int main(){
    freopen("NSPECIAL.INP", "r", stdin);
    freopen("NSPECIAL.OUT", "w", stdout);
    cin >> input;
    ll result;
    result = nspecial();
    cout << result;
    return 0;
}
