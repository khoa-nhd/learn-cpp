#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sum = 0;
ll n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; ++i){
        ll temp;
        cin >> temp;
        sum += temp;
    }
    cout << sum;
    return 0;
}
