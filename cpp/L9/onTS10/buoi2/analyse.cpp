#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

bool prime[maxN];
int cnt[maxN] = {};
ll n;

void sangNT(){
    for(int i = 2; i < maxN; ++i) prime[i] = true;
    for(int i = 2; i < maxN; ++i){
        if(prime[i]){
            for(int j = i * i; j < maxN; j += i) prime[j] = false;
        }
    }
}

void phantich(int x){
    for(int i = 2; i * i <= x; ++i){
        if(prime[i]){
            while(x % i == 0){
                cnt[i] += 1;
                x /= i;
            }
        }
    }
    if(x > 1) cnt[x] += 1;
}

void analyse(){
    for(int i = 0; i <= n; ++i) cnt[i] = 0;
    for(int i = 2; i <= n; ++i){
        phantich(i);
    }
    for(int i = 0; i <= n; ++i){
        if(prime[i]) cout << cnt[i] << " ";
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
   sangNT();
    while(cin >> n){
        analyse();
    }
    return 0;
}
