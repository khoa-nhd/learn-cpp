#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 20000005

bool prime[maxN] = {};
vector<ll> primeNums;

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

void addPrimeNums(){
    for(int i = 0; i < maxN; ++i){
        if(prime[i]) primeNums.push_back(i);
    }
//    for(int i = 0; i < 10; ++i){
//        cout << primeNums[i] << " ";
//    }
//    cout << "\n";
}

bool checkSymprime(ll n){
    ll low = 0, high = primeNums.size() - 1;
    while(low <= high){
        ll half = (low + high) / 2;
        if(primeNums[half] == n){
            if(primeNums[half - 1] + primeNums[half + 1] == 2 * n) return true;
            else return false;
        }
        if(primeNums[half] <= n) low = half + 1;
        else high = half - 1;
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SYMPRIME.INP", "r", stdin);
    freopen("SYMPRIME.OUT", "w", stdout);
    sangNguyenTo();
    addPrimeNums();
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        ll n;
        cin >> n;
        if(checkSymprime(n)) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}
