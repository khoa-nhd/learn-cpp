#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 10000000

ll n, a[maxN];

void readData(){
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
    }
}

bool nhantinh(){
    for(int i = 1; i * i <= n; ++i){
        for(int j = i; i*j <= n; ++j){
            if(a[i*j] != a[i]*a[j]) return false;
        }
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    readData();
    if(nhantinh()) cout << "YES";
    else cout << "NO";
    return 0;
}
