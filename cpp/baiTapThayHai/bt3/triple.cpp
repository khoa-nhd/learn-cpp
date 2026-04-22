#include <bits/stdc++.h>
using namespace std;
#define maxN 5005
typedef long long ll;

ll n, a[maxN];


void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void solve(){
    sort(a, a + n);
    for(int i = 0; i < n-2; ++i){
        for(int j = i + 1; j < n-1; ++j){
            ll target = 2*a[j] - a[i];
            if(binary_search(a + j + 1, a + n, target) && (2*a[j] - a[i]) - a[j] > 0){
                cout << a[i] << " " << a[j] << " " << (2*a[j] - a[i]);
                return;
            }
        }
    }
    cout << "0 0 0";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TRIPLE.INP", "r", stdin);
    freopen("TRIPLE.OUT", "w", stdout);
    readData();
    solve();
    return 0;
}
