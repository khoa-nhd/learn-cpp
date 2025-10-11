#include <bits/stdc++.h>
using namespace std;
#define maxN 50005
typedef long long ll;

ll n;
pair<ll, ll> a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first >> a[i].second;
    }
}

ll searchh(int d, int c, ll target){
    ll result = -1;
    while(d <= c){
        int half = (d+c)/2;
        if(a[half].first < target){
            result = half;
            d = half + 1;
        } else {
            c = half - 1;
        }
    }
    return result;
}

ll tvshow(){
    ll result = 0, num;
    sort(a, a+n);
    for(int i = 0; i < n; ++i){
        int it = searchh(i+1, n-1, a[i].second);
        if(it != -1){
            num = it - i;
            result += num;
        }
    }
    return result;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TVSHOW.INP", "r", stdin);
    freopen("TVSHOW.OUT", "w", stdout);
    readData();
    ll m;
    m = tvshow();
    cout << m;
    return 0;
}
