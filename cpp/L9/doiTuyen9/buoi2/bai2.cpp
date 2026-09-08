#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    bool taken[10] = {false, false, true, true, false, true, false, true, false, false};
    ll n;
    cin >> n;

    ll xet = 0;

    while(n > 0){
        xet *= 10;
        xet += n % 10;
        n /= 10;
    }

    while(xet > 0){
        if(taken[xet % 10]){
            cout << xet % 10 << " ";
            taken[xet % 10] = false;
        }
        xet /= 10;
    }
    return 0;
}
