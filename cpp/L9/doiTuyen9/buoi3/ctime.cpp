#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 5005

ll n;
pair<ll, ll> a[maxN] = {};

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
    }
}

void ctime(){
    ll koNgLm = LLONG_MIN;
    ll min1nglm = LLONG_MIN;
    sort(a, a+n);
    ll batDau = a[0].first;
    ll ketThuc = a[0].second;
    for(int i = 1; i < n; ++i){
        if(a[i].first > ketThuc){
            koNgLm = max(koNgLm, a[i].first - ketThuc);
            min1nglm = max(min1nglm, ketThuc - batDau);
            batDau = a[i].first;
            ketThuc = a[i].second;
            min1nglm = max(min1nglm, ketThuc - batDau);
        } else{
            ketThuc = max(a[i].second, ketThuc);
        }
    }
    min1nglm = max(min1nglm, ketThuc - batDau);
    koNgLm = max(0LL, koNgLm);
    cout << min1nglm << " " << koNgLm;
}

int main(){
    readData();
    ctime();
    return 0;
}
