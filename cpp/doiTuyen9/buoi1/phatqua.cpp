#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll phatqua(ll a, ll b){
    int sqrta = sqrt(a);
    ll result = 0;
    for(int i = 1; i <= sqrta; ++i){
        if(a % i == 0 && i*i != a){
            ll conlai = a/i;
            if(b % i == 0){
                result += 1;
            }
            if(b % conlai == 0){
                result += 1;
            }
        } else if(i*i == a){
            if(b % i == 0){
                result += 1;
            }
        }
    }
    return result;
}

int main(){
    ll a, b;
    cin >> a >> b;
    ll m;
    m = phatqua(a, b);
    cout << m;
    return 0;
}
