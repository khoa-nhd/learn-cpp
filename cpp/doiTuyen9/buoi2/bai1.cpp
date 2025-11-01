#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 10000000

queue<ll> res;
vector<ll> ans;
ll minn = 1, maxx = 10;

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

void SNT(ll n){
    res.push(2);
    res.push(3);
    res.push(5);
    res.push(7);
    for(int i = 1; i < n; ++i){
        ll loop = res.size();
        for(int k = 0; k < loop; ++k){
            ll temp = res.front();
            res.pop();
            for(int j = 1; j <= 9; j += 2){
                if(checkPrime(temp * 10 + j)) res.push(temp * 10 + j);
            }
        }
    }
    while(!res.empty()){
        ans.push_back(res.front());
        res.pop();
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i] << "\n";
    }
}

int main(){
    ll n;
//    n = 8;
    cin >> n;
    for(int i = 1; i < n; ++i){
        minn *= 10;
        maxx *= 10;
    }
    maxx -= 1;
    SNT(n);
    return 0;
}
