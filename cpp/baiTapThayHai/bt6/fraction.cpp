#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll d[maxN] = {};
ll uocNguyenToA[maxN] = {};
ll uocNguyenToB[maxN] = {};

void sang(){
    for(int i = 2; i*i < maxN; ++i){
        if(d[i] == 0){
            for(int j = i; j*i < maxN; ++j){
                d[i*j] = i;
            }
        }
    }
}

void phanTich(ll x, ll uocNguyenTo[]){
    while(x > 1){
        ll p = d[x];
        if(p == 0) p = x;
        while(x % p == 0){
            x /= p;
            uocNguyenTo[p] += 1;
        }
    }
}

void thietLap(){
    for(int i = 0; i < maxN; ++i){
        uocNguyenToA[i] = 0;
        uocNguyenToB[i] = 0;
    }
    ll n;
    ll temp;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> temp;
        phanTich(temp, uocNguyenToA);
    }
    for(int i = 0; i < n; ++i){
        cin >> temp;
        phanTich(temp, uocNguyenToB);
    }
}

void toiGian(){
    for(int i = 0; i < maxN; ++i){
        if(uocNguyenToA[i] > uocNguyenToB[i]){
            uocNguyenToA[i] -= uocNguyenToB[i];
            uocNguyenToB[i] = 0;
        } else{
            uocNguyenToB[i] -= uocNguyenToA[i];
            uocNguyenToA[i] = 0;
        }
    }
}

void fraction(){
    thietLap();
    toiGian();
    for(int i = 0; i < maxN; ++i){
        if(uocNguyenToB[i] > 0 && i != 2 && i != 5){
            cout << "repeating" << "\n";
            return;
        }
    }
    cout << "finite" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("FRACTION.INP", "r", stdin);
    freopen("FRACTION.OUT", "w", stdout);
    sang();
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        fraction();
    }
    return 0;
}
