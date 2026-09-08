#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, k, a[maxN];

void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll tongThoiGian(ll xeDauTien){
    ll res = 0;
    for(int i = 0; i < n; ++i){
        ll xe = (a[i] - xeDauTien) / k;
        if(xe * k + xeDauTien < a[i]) xe += 1;
        res += (xe * k + xeDauTien) - a[i];
    }
    return res;
}

ll tgLauNhat(ll xeDauTien){
    ll res = LLONG_MIN;
    for(int i = 0; i < n; ++i){
        ll xe = (a[i] - xeDauTien) / k;
        if(xe * k + xeDauTien < a[i]) xe += 1;
        res = max(res, (xe * k + xeDauTien) - a[i]);
    }
    return res;
}

void buses(){
    ll minTong = LLONG_MAX;
    ll minLauNhat = LLONG_MAX;
    ll resMinTong = -1;
    ll resMinLauNhat = -1;
    for(int i = 0; i < k; ++i){
        ll tong = tongThoiGian(i);
        if(tong < minTong){
            minTong = tong;
            resMinTong = i;
        }
        ll maxTg = tgLauNhat(i);
        if(maxTg < minLauNhat){
            minLauNhat = maxTg;
            resMinLauNhat = i;
        }
    }
    cout << minTong << " " << resMinTong << "\n";
    cout << minLauNhat << " " << resMinLauNhat << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BUSES.INP", "r", stdin);
    freopen("BUSES.OUT", "w", stdout);
    readData();
    buses();
    return 0;
}
