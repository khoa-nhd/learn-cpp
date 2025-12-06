#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll l, r, p;
ll lastNumL[10] = {};
ll lastNumR[10] = {};

void calLastNum(ll n, int lastNum, ll arr[]){
    ll lastVal = 0;
    for(int i = n; i >= 0; --i){
        if(i % 10 == lastNum){
            lastVal = i;
            break;
        }
    }
    if(lastVal == 0) return;
    ll num = ((lastVal - lastNum) / 10) + 1;
    arr[lastNum] = num;
}

ll sol(){
    ll res = 0;
    for(int i = 0; i < 10; ++i){
        calLastNum(l-1, i, lastNumL);
        calLastNum(r, i, lastNumR);
    }
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < 10; ++j){
            if((i * j) % 10 == p){
                res += (lastNumR[i] - lastNumL[i]) * (lastNumR[j] - lastNumL[j]);
            }
        }
    }
    return res;
}

int main(){
    cin >> l >> r >> p;
    ll res;
    res = sol();
    cout << res;
    return 0;
}
