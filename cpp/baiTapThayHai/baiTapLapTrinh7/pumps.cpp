#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll b, d;

void test(){
    for(int c = 0; c < b; ++c){
        if((b*b - c*b) % d == 0){
            cout << c << " " << (b*b - c*b) / d << "\n";
        }
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("i.INP", "r", stdin);
    freopen("o.OUT", "w", stdout);
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> b >> d;
        test();
    }
    return 0;
}
