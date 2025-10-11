#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000
typedef long long ll;

ll n, a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll container(){
    ll maxx = -1, current;
    int i = 0, j = n-1;
    while(i <= j){
        current = (j-i) * min(a[i], a[j]);
        maxx = max(maxx, current);
        if(a[i] > a[j]){
            j -= 1;
        } else{
            i += 1;
        }
    }
    return maxx;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CONTAINER.INP", "r", stdin);
    freopen("CONTAINER.OUT", "w", stdout);
    readData();
    ll m;
    m = container();
    cout << m;
    return 0;
}
