#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> bigint;
#define maxN 1000005

ll n;
struct{
    ll soLuongSo, giaTriDau, giaTriCuoi;
} nhom[maxN];

void test(){
    ll curr = 0;
    ll cnt = 0;
    for(int i = 1; cnt < n; ++i){
        for(int j = 0; j < i && cnt < n; ++j){
            cout << i - curr % i << " ";
            curr += i - curr%i;
            cout << curr << "\n";
            cnt += 1;
        }
    }
    cout << curr;
    cout << n;
}

ll sequence(){
    nhom[0].soLuongSo = 0;
    nhom[0].giaTriCuoi = 0;
    nhom[0].giaTriDau = 0;
    ll i = 1;
    while(nhom[i-1].soLuongSo < n){
        nhom[i].soLuongSo = nhom[i-1].soLuongSo + i;
        nhom[i].giaTriDau = (nhom[i-1].giaTriCuoi / i + 1) * i;
        nhom[i].giaTriCuoi = nhom[i].giaTriDau + (i-1)*i;
        i += 1;
    }
    i -= 1;
    ll res = nhom[i].giaTriDau + i * (n - nhom[i-1].soLuongSo - 1);
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SEQUENCE.INP", "r", stdin);
    freopen("SEQUENCE.OUT", "w", stdout);
    cin >> n;
//    test();
    ll res;
    res = sequence();
    cout << res;
    return 0;
}
