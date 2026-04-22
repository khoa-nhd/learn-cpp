#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 300000

ll dp[45] = {};
bool prime[maxN] = {};
ll prefix[maxN] = {};

void genSoCach(){
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    for(int i = 5; i <= 40; ++i){
        dp[i] = dp[i-1] + dp[i-4];
    }
}

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

void prefixNguyenTo(){
    for(int i = 2; i < maxN; ++i){
        if(prime[i]) prefix[i] += 1;
        prefix[i] += prefix[i-1];
    }
}

int main(){
    freopen("YARD.INP", "r", stdin);
    freopen("YARD.OUT", "w", stdout);
    genSoCach();
    sangNguyenTo();
    prefixNguyenTo();
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        ll n;
        cin >> n;
        cout << prefix[dp[n]] << "\n";
    }
    return 0;
}
