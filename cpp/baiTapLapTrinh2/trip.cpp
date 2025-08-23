#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void trip(ll n){
    ll m, a[n] = {}, result = 0;
    cin >> m;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    sort(a, a+n);
    int i = 0, j = n-1;
    while(i <= j){
        if(a[i] + a[j] <= m){
            result += 1;
            i += 1;
            j -= 1;
        } else{
            result += 1;
            j -= 1;
        }
    }
    cout << result << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TRIP.INP", "r", stdin);
    freopen("TRIP.OUT", "w", stdout);
    ll n;
    while(cin >> n){
        trip(n);
    }
    return 0;
}
