#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

void fraction(ll n){
    ll r = 1, s = 1;
    vector<string> b;
    while(n > 1){
        if(n % 2 == 0){
            b.push_back("trai");
        } else{
            b.push_back("phai");
        }
        n = n/2;
    }



    for(int i = b.size() - 1; i >= 0; --i){
        if(b[i] == "trai"){
            s = r + s;
        } else{
            r = r + s;
        }
    }
    cout << r << " " << s;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("FRACTION.INP", "r", stdin);
    freopen("FRACTION.OUT", "w", stdout);
    ll n;
    cin >> n;
    fraction(n+1);
    return 0;
}
