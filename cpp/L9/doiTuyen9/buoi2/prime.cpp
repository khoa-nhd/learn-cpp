#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n;
    bool isPrime = true;
    cin >> n;
    if(n < 2){
        cout << "NO";
    } else{
        ll loop = sqrt(n);
        for(int i = 2; i <= loop; ++i){
            if(n % i == 0){
                isPrime = false;
            }
        }
        if(isPrime) cout << "YES";
        else cout << "NO";
    }
    return 0;
}
