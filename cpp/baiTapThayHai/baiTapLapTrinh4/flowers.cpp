#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

ll n, m, s, a[maxN];
pair<ll, ll> b[maxN];

void readData(){
    cin >> n >> m >> s;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < m; ++i){
        cin >> b[i].first;
        b[i].second = i;
    }
}

ll lowerThanOrEqualTo(int d, int c, ll target){
    ll result = -1;
    while(d <= c){
        ll half = (d + c) / 2;
        if(b[half].first <= target){
            result = half;
            d = half + 1;
        } else{
            c = half - 1;
        }
    }
    return result;
}

void flowers(){
    sort(b, b + m);
    ll maxCost = LLONG_MIN, mindiff = LLONG_MAX;
    ll maxI = -1, maxJ = -1;
    for(int i = 0; i < n; ++i){
        ll need = s - a[i];
        ll nhoHonHoacBang = lowerThanOrEqualTo(0, m - 1, need);
        if(nhoHonHoacBang != -1){
            if(maxCost <= a[i] + b[nhoHonHoacBang].first){
                if(maxCost == a[i] + b[nhoHonHoacBang].first){
                    if(abs(a[i] - b[nhoHonHoacBang].first) < mindiff){
                        maxCost = a[i] + b[nhoHonHoacBang].first;
                        maxI = i;
                        maxJ = b[nhoHonHoacBang].second;
                        mindiff = abs(a[i] - b[nhoHonHoacBang].first);
                    }
                } else{
                    maxCost = a[i] + b[nhoHonHoacBang].first;
                    maxI = i;
                    maxJ = b[nhoHonHoacBang].second;
                    mindiff = abs(a[i] - b[nhoHonHoacBang].first);
                }
            }
        }
    }
    cout << maxI + 1 << " " << maxJ + 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("FLOWERS.INP", "r", stdin);
    freopen("FLOWERS.OUT", "w", stdout);
    readData();
    flowers();
    return 0;
}
