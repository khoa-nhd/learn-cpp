#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

struct{
    ll pre1, pre2, td;
    char cd;
} arr[maxN];
ll n, t, q;
ll nguyenR, canR;
ll nguyenL, canL;

void readData(){
    cin >> n >> t >> q;
    arr[0].pre1 = 0;
    arr[0].pre2 = 0;
    arr[0].td = 0;
    arr[0].cd = '-';
    for(int i = 1; i <= n; ++i){
        cin >> arr[i].td >> arr[i].cd;
        arr[i].pre1 = arr[i-1].pre1;
        arr[i].pre2 = arr[i-1].pre2;
        if(arr[i-1].cd == '-'){
            arr[i].pre1 += arr[i].td - arr[i-1].td;
        } else{
            arr[i].pre2 += arr[i].td - arr[i-1].td;
        }
    }
    arr[n+1].pre1 = arr[n].pre1;
    arr[n+1].pre2 = arr[n].pre2;
    arr[n+1].td = t;
    if(arr[n].cd == '-'){
        arr[n+1].pre1 += arr[n+1].td - arr[n].td;
    } else{
        arr[n+1].pre2 += arr[n+1].td - arr[n].td;
    }
}

void caldist(ll x, ll &nguyen, ll &can){
    ll d = 0, c = n + 1;
    ll diem = -1;
    while(d <= c){
        ll half = (d + c) / 2;
        if(arr[half].td <= x){
            diem = half;
            d = half + 1;
        } else{
            c = half - 1;
        }
    }
    nguyen = arr[diem].pre1;
    can = arr[diem].pre2;
    if(arr[diem].cd == '-'){
        nguyen += x - arr[diem].td;
    } else{
        can += x - arr[diem].td;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    for(int i = 0; i < q; ++i){
        ll l, r;
        cin >> l >> r;
        caldist(l, nguyenL, canL);
        caldist(r, nguyenR, canR);
        nguyenR -= nguyenL;
        canR -= canL;
        double res;
        res = nguyenR + sqrt(2)*canR;
        cout << fixed << setprecision(6) << res << "\n";
    }
    return 0;
}
