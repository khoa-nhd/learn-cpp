#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll arr[maxN] = {};

void ghh(){
    for(int i = 1; i < maxN; ++i){
        for(int j = i; j < maxN; j += i){
            arr[j] += i;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    ghh();
    for(int i = 0; i < t; ++i){
        ll m;
        cin >> m;
        if(arr[m] >= 2*m){
            cout << 1 << "\n";
        } else{
            cout << 0 << "\n";
        }
    }
    return 0;
}
