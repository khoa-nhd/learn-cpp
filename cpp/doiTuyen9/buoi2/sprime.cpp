#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 3000005

bool sprime[maxN] = {};
ll preSprime[maxN] = {};

bool checkSumNumChiaHet5(int n){
    ll sumNum = 0;
    while(n > 0){
        sumNum += n % 10;
        n /= 10;
    }
    if(sumNum % 5 == 0) return true;
    return false;
}

void sangNguyenToDacBiet(){
    for(int i = 2; i < maxN; ++i){
        sprime[i] = true;
    }
    for(int i = 2; i * i < maxN; ++i){
        if(sprime[i]){
            for(int j = i * i; j < maxN; j += i){
                sprime[j] = false;
            }
        }
    }
    for(int i = 0; i < maxN; ++i){
        if(sprime[i] && !checkSumNumChiaHet5(i)){
            sprime[i] = false;
        }
    }
}

void prefixSprime(){
    for(int i = 1; i < maxN; ++i){
        preSprime[i] = preSprime[i - 1];
        if(sprime[i]){
            preSprime[i] += 1;
        }
    }
}

int main(){
    sangNguyenToDacBiet();
    prefixSprime();
    ll t;
    cin >> t;
//    for(int i = 0; i < 10; ++i){
//        cout << sprime[i] << " ";
//    }
//    cout << "\n";
    for(int i = 0; i < t; ++i){
        ll l, r;
        cin >> l >> r;
//        cout << preSprime[r] << " " << preSprime[l-1] << " ";
        cout << preSprime[r] - preSprime[l-1] << "\n";
    }
    return 0;
}
