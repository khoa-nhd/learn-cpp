#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll values[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void lonNhat(ll n, ll k) {
    for(int i = 0; i < n; ++i){
        for(int j = 9; j >= 0; --j){
            ll cost = values[j];
            ll rempos = n - i - 1;
            ll remk = k - cost;
            if(remk < 0) {
                continue;
            }
            if(rempos*2 <= remk && rempos*7 >= remk){
                cout << j;
                k = remk;
                break;
            }
        }
    }
}

void nhoNhat(ll n, ll k){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j <= 9; ++j){
            if(i == 0 && j == 0) {
                continue;
            }
            ll cost = values[j];
            ll rempos = n - i - 1;
            ll remk = k - cost;
            if(remk < 0){
                continue;
            }
            if(rempos*2 <= remk && rempos*7 >= remk){
                cout << j;
                k = remk;
                break;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("LED.INP", "r", stdin);
    freopen("LED.OUT", "w", stdout);
    ll n, k;
    cin >> n >> k;
    if(n*2 > k || n*7 < k){
        cout << "NO SOLUTION";
    } else {
        nhoNhat(n, k);
        cout << "\n";
        lonNhat(n, k);
    }
    return 0;
}
