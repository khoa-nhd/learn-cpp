#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000
typedef long long ll;

ll n, k, a[maxN];

void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll lastnum(){
    ll result = 1;
    for(int i = 0; i < 18; ++i){
        result *= 10;
    }
    return result;
}

bool dusanpham(ll thoigian){
    ll sosanpham = 0;
    for(int i = 0; i < n; ++i){
        sosanpham += thoigian/a[i];
        if(sosanpham >= k){
            break;
        }
    }
    return sosanpham >= k;
}

ll machines(){
    ll d = 0, c = lastnum();
    ll result = 0;
    while(d <= c){
        ll half = (d+c)/2;
        if(dusanpham(half)){
            result = half;
            c = half - 1;
        } else{
            d = half + 1;
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MACHINES.INP", "r", stdin);
    freopen("MACHINES.OUT", "w", stdout);
    readData();
    ll m;
    m = machines();
    cout << m;
    return 0;
}
