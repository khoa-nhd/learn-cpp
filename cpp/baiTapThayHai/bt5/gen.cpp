#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define maxN 1005
#define maxN2 2200005

vector<ull> a, b;
bool prime[maxN2] = {};
ull dp[maxN][maxN] = {};
vector<ull> c, d;


void readData(){
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
//    s1.push_back(' ');
//    s2.push_back(' ');
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
    for(int i = 2; i < maxN2; ++i) prime[i] = true;
    for(int i = 2; i * i < maxN2; ++i){
        if(prime[i]){
            for(int j = i * i; j < maxN2; j += i){
                prime[j] = false;
            }
        }
    }
}

bool check(ull n){
    ull square = sqrtl(n);
    ull cube = cbrtl(n);
//    ull temp = cube * cube * cube;
//    bool temp2 = prime[cube];
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
//        cout << x << " ";
    }
//    cout << "\n";
    for(ull x : b){
        if(check(x)){
            d.push_back(x);
        }
//        cout << x << " ";
    }
//    cout << "\n";
}

ull gen(){
//    for(ull x : c) cout << x << " ";
//    cout << "\n";
//    for(ull x : d) cout << x << " ";
//    cout << "\n";
    for(int i = 1; i < c.size(); ++i){
        for(int j = 1; j < d.size(); ++j){
            if(c[i] == d[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            } else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[c.size()-1][d.size()-1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("GEN.INP", "r", stdin);
    freopen("GEN.OUT", "w", stdout);
    sangNguyenTo();
    readData();
    loc();
    ull res;
    res = gen();
    cout << res;
    return 0;
}
