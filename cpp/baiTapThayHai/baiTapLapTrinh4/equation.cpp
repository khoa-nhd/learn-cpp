#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 5005

bool prime[maxN] = {};

void sangNguyenTo(){
    for(int i = 2; i < maxN; ++i){
        prime[i] = true;
    }
    for(int i = 2; i * i < maxN; ++i){
        if(prime[i]){
            for(int j = i * i; j < maxN; j += i){
                prime[j] = false;
            }
        }
    }
}

ll equation(int n){
    ll res = 0;
    for(int i = 0; i < n; ++i){
        if(prime[i]){
            for(int j = i; i + j < n; ++j){
                if(prime[j]){
                    int k = n - i - j;
                    if(prime[k] && k >= i) res += 1;
                }
            }
        }
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("EQUATION.INP", "r", stdin);
    freopen("EQUATION.OUT", "w", stdout);
    sangNguyenTo();
    ll n;
    while(cin >> n){
        ll res;
        res = equation(n);
        cout << res << "\n";
    }
    return 0;
}
