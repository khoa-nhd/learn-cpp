#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1005

ll luckyNum[maxN];

void genLuckyNum(){
    luckyNum[0] = 1;
    ll i3 = 0;
    ll i5 = 0;
    ll i7 = 0;
    for(int i = 1; i < maxN; ++i){
        ll val3 = luckyNum[i3] * 3;
        ll val5 = luckyNum[i5] * 5;
        ll val7 = luckyNum[i7] * 7;
        ll minn = min(val3, min(val5, val7));
        luckyNum[i] = minn;
        if(val3 == minn) i3 += 1;
        if(val5 == minn) i5 += 1;
        if(val7 == minn) i7 += 1;
//        cout << luckyNum[i] << "\n";
    }
}

ll binarysearch(ll target){
    int d = 1;
    int c = 1000;
    while(d <= c){
        ll half = (d + c) / 2;
        if(luckyNum[half] == target){
            return half;
        }
        if(luckyNum[half] > target){
            c = half - 1;
        } else{
            d = half + 1;
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("STREET.INP", "r", stdin);
    freopen("STREET.OUT", "w", stdout);
    ll n;
    genLuckyNum();
    while(cin >> n){
        ll idx;
        idx = binarysearch(n);
        if(idx == -1){
            cout << "N";
        } else if(idx % 2 == 0){
            cout << "R";
        } else{
            cout << "L";
        }
        cout << "\n";
    }
    return 0;
}
