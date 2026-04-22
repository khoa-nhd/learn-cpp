#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, k, a[maxN];

void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll countPair(ll num){
    ll result = 0;
    ll d = 0, c = n-1;
    while(d <= c){
        if(a[d] + a[c] <= num){
            result += c - d;
            d += 1;
        } else{
            c -= 1;
        }
    }
    return result;
}

ll kthsum(){
    ll result = -1;
    sort(a, a + n);
    ll low = a[0] + a[1];
    ll high = a[n-1] + a[n-2];
    while(low <= high){
        ll half = (low + high) / 2;
        ll pairs = countPair(half);
        if(pairs >= k){
            result = half;
            high = half - 1;
        } else{
            low = half + 1;
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("KTHSUM.INP", "r", stdin);
    freopen("KTHSUM.OUT", "w", stdout);
    readData();
    ll result;
    result = kthsum();
    cout << result;
    return 0;
}
