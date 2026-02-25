#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define maxN 2500000

vector<ll> a, b, c, d;
bool prime[maxN] = {};
ll dp[1005][1005] = {};

void readData(){
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    ull temp = 0;
    for(char x : s1){
        if(x == ' '){
            a.push_back(temp);
            temp = 0;
        } else{
            temp *= 10;
            temp += x - '0';
        }
    }
    temp = 0;
    for(char x : s2){
        if(x == ' '){
            b.push_back(temp);
            temp = 0;
        } else{
            temp *= 10;
            temp += x - '0';
        }
    }
}

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

bool check(ull n){
    ull square = sqrtl(n);
    ull cube = cbrtl(n);
    if(square * square == n || (cube * cube * cube == n && prime[cube])){
        return true;
    }
    return false;
}

void loc(){
    c.push_back(0);
    d.push_back(0);
    for(ull x : a){
        if(check(x)){
            c.push_back(x);
        }
    }
    for(ull x : b){
        if(check(x)){
            d.push_back(x);
        }
    }
}

ll gen(){
    for(int i = 1; i < c.size(); ++i){
        for(int j = 1; j < d.size(); ++j){
            if(c[i] == d[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[c.size()-1][d.size()-1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("GEN.INP", "r", stdin);
    freopen("GEN.OUT", "w", stdout);
    readData();
    sangNguyenTo();
    loc();
    ll res;
    res = gen();
    cout << res;
    return 0;
}
