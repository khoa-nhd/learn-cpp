#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

ll n, t;
pair<ll, ll> a[maxN];

void readData(){
    cin >> n >> t;
    for(int i = 0; i < n; ++i){
        cin >> a[i].first;
        a[i].second = i;
    }
}

ll mysearch(int d, int c, ll target){
    ll result = -1;
    while(d <= c){
        ll half = (d+c)/2;
        if(target >= a[half].first){
            result = half;
            d = half + 1;
        } else{
            c = half - 1;
        }
    }
    return result;
}

void maxproduct(){
    sort(a, a + n);
    ll maxx = -1;
    ll vitri1, vitri2;
    for(int i = 0; i < n; ++i){
        ll conlai = t / a[i].first;
        ll idx = mysearch(i+1, n-1, conlai);
        if(idx != -1){
            if(a[idx].first * a[i].first > maxx){
                maxx = a[idx].first * a[i].first;
                vitri1 = a[i].second;
                vitri2 = a[idx].second;
            }
        }
    }
    if(maxx != -1){
        cout << maxx << "\n";
        cout << vitri1+1 << " " << vitri2+1;
    } else{
        cout << 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MAXPRODUCT.INP", "r", stdin);
    freopen("MAXPRODUCT.OUT", "w", stdout);
    readData();
    maxproduct();
    return 0;
}
