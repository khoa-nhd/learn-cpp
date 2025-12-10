#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll t, n, a[maxN] = {};

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void distribution(){
    double prefix[maxN] = {};
    prefix[0] =  (double)a[0] / 2;
    for(int i = 1; i < n; ++i){
        prefix[i] = prefix[i-1] + (double)a[i] / 2;
    }
    double suffix[maxN] = {};
    suffix[n-1] = a[n-1];
    for(int i = n-2; i >= 0; --i){
        suffix[i] = suffix[i+1] + a[i];
    }
    ll i = 0;
    ll j = n-1;
    while(i < j-1){
        if(prefix[i] <= suffix[j]) i += 1;
        else j -= 1;
    }
    cout << i+1 << " " << n-i-1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("DISTRIBUTION.INP", "r", stdin);
    freopen("DISTRIBUTION.OUT", "w", stdout);
    ll t;
    cin >> t;
    for(int i = 0; i < t; ++i){
        readData();
        distribution();
    }
    return 0;
}
