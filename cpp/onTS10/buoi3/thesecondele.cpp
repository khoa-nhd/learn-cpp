#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000005

ll a[maxN];
ll n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    sort(a, a + n);
    cout << a[n-2];
    return 0;
}
