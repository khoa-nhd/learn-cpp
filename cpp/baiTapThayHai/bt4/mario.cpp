#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll n, a[maxN];
ll maxVal = LLONG_MIN;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        maxVal = max(maxVal, a[i]);
    }
}

bool checkPossible(ll energy){
    for(int i = 0; i < n; ++i){
        if(energy >= a[i]){
            energy += abs(energy - a[i]);
        } else{
            energy -= abs(energy - a[i]);
        }
        if(energy > maxVal){
            return true;
        }
        if(energy < 0){
            return false;
        }
    }
    return true;
}

ll mario(){
    ll result;
    ll low = 0, high = 1000000;
    while(low <= high){
        ll half = (low + high) / 2;
        if(checkPossible(half)){
            high = half - 1;
            result = half;
        } else{
            low = half + 1;
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MARIO.INP", "r", stdin);
    freopen("MARIO.OUT", "w", stdout);
    readData();
    ll result;
    result = mario();
    cout << result;
    return 0;
}
