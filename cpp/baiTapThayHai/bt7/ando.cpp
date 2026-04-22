#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 300005

ll n, a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll ando(){
    for(int i = 32; i >= 0; --i){
        int sl = 0;
        for(int j = 0; j < n; ++j){
            if(((a[j] >> i) & 1) == 1) sl += 1;
        }
        if(sl >= 2){
            for(int j = 0; j < n; ++j){
                if(((a[j] >> i) & 1) == 0) a[j] = 0;
//                cout << a[j] << " ";
            }
//            cout << "\n";
        }
    }
    int prev = -1;
    for(int i = 0; i < n; ++i){
        if(a[i] != 0){
            if(prev == -1) prev = i;
            else return (a[prev] & a[i]);
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ANDO.INP", "r", stdin);
    freopen("ANDO.OUT", "w", stdout);
    readData();
    ll res;
    res = ando();
    cout << res;
    return 0;
}
