#include <bits/stdc++.h>
using namespace std;
#define maxN 100005
typedef long long ll;

ll n, a[maxN], maxx = -1;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if(a[i] > maxx){
            maxx = a[i];
        }
    }
}

ll merlin(){
    sort(a, a + n);
    ll sum = 0;
    for(int i = 0; i < n; ++i){
        sum += a[i];
    }
    ll s1 = 0, s2 = 0;
    for(int i = n-1; i >= 0; --i){
        s1 = 0;
        for(int j = n-1; j > i; --j){
            s1 += a[j];
        }
        s2 = a[i]*(i+1) - (sum - s1);
        if(s1 >= s2){
            return n-(i+1);
        }
    }
    return n-1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MERLIN.INP", "r", stdin);
    freopen("MERLIN.OUT", "w", stdout);
    readData();
    ll m;
    m = merlin();
    cout << m;
    return 0;
}
