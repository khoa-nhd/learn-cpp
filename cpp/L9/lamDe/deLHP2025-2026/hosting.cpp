#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

ll n;

struct khach{
    ll x, d, k, y;
} a[maxN];

ll dungLuong[maxN] = {};
ll ngayBatDau = LLONG_MAX;
ll ngayKetThuc = LLONG_MIN;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].x >> a[i].d >> a[i].k;
        a[i].y = a[i].x + a[i].d - 1;
        ngayBatDau = min(ngayBatDau, a[i].x);
        ngayKetThuc = max(ngayKetThuc, a[i].y);
    }
}

void sol(){
    for(int i = 0; i < n; ++i){
        dungLuong[a[i].x] += a[i].k;
        dungLuong[a[i].y + 1] += -a[i].k;
    }
//    for(int i = 1; i < maxN; ++i){
//        if(i >= ngayBatDau && i <= ngayKetThuc) cout << dungLuong[i] << " ";
//    }
//    cout << "\n";
    for(int i = 1; i < maxN; ++i){
        dungLuong[i] += dungLuong[i-1];
//        if(i >= ngayBatDau && i <= ngayKetThuc) cout << dungLuong[i] << " ";
    }
//    cout << "\n";
    for(int i = ngayBatDau; i <= ngayKetThuc; ++i){
        if(dungLuong[i] != dungLuong[i-1]) cout << dungLuong[i] << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    sol();
    return 0;
}
