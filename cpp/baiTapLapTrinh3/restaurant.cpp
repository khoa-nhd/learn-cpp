#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

ll n, enter[maxN], out[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> enter[i] >> out[i];
    }
}

ll restaurant(){
    sort(enter, enter + n);
    sort(out, out + n);
    int i = 0, j = 0;
    ll current = 0, maxx = -1;
    while(i < n && j < n){
        if(enter[i] < out[j]){
            current += 1;
            i += 1;
        } else{
            current -= 1;
            j += 1;
        }
        maxx = max(maxx, current);
    }
    return maxx;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("RESTAURANT.INP", "r", stdin);
    freopen("RESTAURANT.OUT", "w", stdout);
    readData();
    ll m = restaurant();
    cout << m;
    return 0;
}
