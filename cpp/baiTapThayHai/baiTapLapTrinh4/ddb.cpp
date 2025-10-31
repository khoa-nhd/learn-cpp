#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 2000005

bool prime[maxN] = {};
ll preSum[maxN] = {};

void sangNguyenTo(){
    for(int i = 2; i < maxN; ++i) prime[i] = true;
    for(int i = 2; i*i < maxN; ++i){
        if(prime[i]){
            for(int j = i * i; j < maxN; j += i){
                prime[j] = false;
            }
        }
    }
}

void prefixSum(){
    for(int i = 1; i < 10; ++i){
        preSum[i] = preSum[i-1];
        if(prime[i]) preSum[i] += 1;
//        cout << preSum[i] << " ";
    }
//    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("DDB.INP", "r", stdin);
    freopen("DDB.OUT", "w", stdout);
    sangNguyenTo();
    prefixSum();
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        ll test;
        cin >> test;
        ll res;
//        cout << "\n" << preSum[2*test] << " " << preSum[test] << "\n";
        res = preSum[2*test] - preSum[test];
        cout << res << "\n";
    }
    return 0;
}
