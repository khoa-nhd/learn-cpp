#include <bits/stdc++.h>
using namespace std;
#define maxN 1000005
typedef long long ll;

ll n, c, k;
pair<ll, ll> a[maxN];

void readData(){
    cin >> n >> c >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
    }
}

ll olymp(){
    ll result = 0;
    ll soLanCan[maxN];
    for(int i = 0; i < n; ++i) {
        if(a[i].first >= k){
            soLanCan[i] = 0;
        } else if(a[i].second > 0){
            soLanCan[i] = ((k - a[i].first) + a[i].second - 1) / a[i].second;
        } else{
            soLanCan[i] = c + 1;
        }
    }
    sort(soLanCan, soLanCan + n);
    for(int i = 0; i < n; ++i){
        if(soLanCan[i] <= 0){
            result += 1;
        } else{
            if(soLanCan[i] <= c){
                c -= soLanCan[i];
                result += 1;
            } else{
                break;
            }
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("OLYMP.INP", "r", stdin);
    freopen("OLYMP.OUT", "w", stdout);
    readData();
    ll m;
    m = olymp();
    cout << m;
    return 0;
}
