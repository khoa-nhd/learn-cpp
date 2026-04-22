#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[5005] = {};

void pythagore(){
    for(int a = 1; a < 2500; ++a){
        for(int b = a; b < 2500; ++b){
            int c =  sqrt(a*a + b*b);
            if(c*c == a*a + b*b && a + b + c <= 5000){
                arr[a+b+c] += 1;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PYTHAGORE.INP", "r", stdin);
    freopen("PYTHAGORE.OUT", "w", stdout);
    ll t;
    cin >> t;
    pythagore();
    for(int i = 0; i < t; ++i){
        ll input;
        cin >> input;
        cout << arr[input] << "\n";
    }
    return 0;
}
