#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, a[maxN], b[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }
}

ll greaterThan(int d, int c, ll target, const ll (&arr)[maxN]){
    ll result = -1;
    while(d <= c){
        ll half = (d + c) / 2;
        if(arr[half] < target){
            result = half;
            d = half + 1;
        } else{
            c = half - 1;
        }
    }
    return result;
}

ll greaterThanOrEqualTo(int d, int c, ll target, const ll (&arr)[maxN]){
    ll result = -1;
    while(d <= c){
        ll half = (d + c) / 2;
        if(arr[half] <= target){
            result = half;
            d = half + 1;
        } else{
            c = half - 1;
        }
    }
    return result;
}

void pigrace(){
    ll pointA = 0;
    ll pointB = 0;
    sort(a, a + n);
    sort(b, b + n);
    for(int i = 0; i < n; ++i){
        ll lonHon = greaterThan(0, n - 1, a[i], b);
        ll lonHonHoacBang = greaterThanOrEqualTo(0, n - 1, a[i], b);
        if(lonHon != -1){
            pointA += (lonHon + 1) * 3;
        }
        if(lonHonHoacBang != -1){
            if(lonHon == -1){
                pointA += lonHonHoacBang + 1;
            } else{
                pointA += (lonHonHoacBang - lonHon);
            }
        }
    }
    for(int i = 0; i < n; ++i){
        ll lonHon = greaterThan(0, n - 1, b[i], a);
        ll lonHonHoacBang = greaterThanOrEqualTo(0, n - 1, b[i], a);
        if(lonHon != -1){
            pointB += (lonHon + 1) * 3;
        }
        if(lonHonHoacBang != -1){
            if(lonHon == -1){
                pointB += lonHonHoacBang + 1;
            } else{
                pointB += (lonHonHoacBang - lonHon);
            }
        }
    }
    cout << pointA << " " << pointB;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PIGRACE.INP", "r", stdin);
    freopen("PIGRACE.OUT", "w", stdout);
    readData();
    pigrace();
    return 0;
}
