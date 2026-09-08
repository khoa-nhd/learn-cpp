#include <bits/stdc++.h>
using namespace std;
#define maxN 100005
typedef long long ll;

void wires(int n){
    int k;
    cin >> k;
    ll a[maxN];
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    ll d = 1, c = a[0];
    for(int i = 0; i < n; ++i){
        if(a[i] > c){
            c = a[i];
        }
    }
    ll maxx = 0;
    while(d <= c){
        ll half = (d+c)/2;
        ll sum = 0;
        for(int i = 0; i < n; ++i){
            sum += a[i]/half;
        }
        if(sum >= k){
            d = half + 1;
            maxx = half;
        } else{
            c = half - 1;
        }
    }
    cout << maxx << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("WIRES.INP", "r", stdin);
    freopen("WIRES.OUT", "w", stdout);
    int n;
    while(cin >> n){
        wires(n);
    }
    return 0;
}
