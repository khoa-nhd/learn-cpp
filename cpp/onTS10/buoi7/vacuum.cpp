#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[105][105] = {};
ll hu = 0;
ll n, k;

void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
            if(a[i][j]) hu += 1;
        }
    }
}

void vacuum(){
    ll l = 0, r = n-1, t = 0, b = n-1;
    ll val = 0;
    ll val2 = (n*n - hu - 1) * 2;
    k %= val2;
    while(l <= r && t <= b){
        for(int i = l; i <= r; ++i){
            if(!a[t][i]){
                if(val == k || val2 == k){
                    cout << t+1 << " " << i+1;
                    return;
                }
                val += 1;
                val2 -= 1;
            }
        }
        for(int i = t + 1; i <= b; ++i){
            if(!a[i][r]){
                if(val == k || val2 == k){
                    cout << i+1 << " " << r+1;
                    return;
                }
                val += 1;
                val2 -= 1;
            }
        }
        if(t < b) for(int i = r - 1; i >= l; --i){
            if(!a[b][i]){
                if(val == k || val2 == k){
                    cout << b+1 << " " << i+1;
                    return;
                }
                val += 1;
                val2 -= 1;
            }
        }
        if(l < r) for(int i = b-1; i >= t + 1; --i){
            if(!a[i][l]){
                if(val == k || val2 == k){
                    cout << i+1 << " " << l+1;
                    return;
                }
                val += 1;
                val2 -= 1;
            }
        }
        r -= 1;
        b -= 1;
        l += 1;
        t += 1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    vacuum();
    return 0;
}
