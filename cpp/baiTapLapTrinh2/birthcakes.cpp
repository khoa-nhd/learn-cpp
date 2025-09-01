#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000
typedef long long ll;

ll n;
ll a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll birthcakes() {
    ll result = n;
    sort(a, a+n);
    int i = 0, j = n/2;
    while(i < n/2 && j < n){
        if(a[i]*2 <= a[j]){
            result -= 1;
            i += 1;
            j += 1;
        } else{
            j += 1;
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BIRTHCAKES.INP", "r", stdin);
    freopen("BIRTHCAKES.OUT", "w", stdout);
    readData();
    ll m;
    m = birthcakes();
    cout << m;
    return 0;
}
