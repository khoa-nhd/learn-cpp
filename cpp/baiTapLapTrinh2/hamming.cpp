#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

set<ll> hammingset;
vector<ll> hammingvec;

void generateHamming(){
    ll i = 1, j = 1, k = 1;
    ll maxx = 1000000000000000000;
    for (ll i = 1; i <= maxx; i *= 2) {
        for (ll j = 1; i * j <= maxx; j *= 3) {
            for (ll k = 1; i * j * k <= maxx; k *= 5) {
                hammingset.insert(i * j * k);
                if (k > maxx / 5) break;
            }
            if (j > maxx / 3) break;
        }
        if (i > maxx / 2) break;
    }
    for(ll value : hammingset){
        hammingvec.push_back(value);
    }
}

ll findHamPos(ll target){
    ll d = 0, c = hammingvec.size()-1;
    while(d <= c){
        ll half = (d+c)/2;
        if(target == hammingvec[half]){
            return half;
        }
        if(hammingvec[half] > target){
            c = half - 1;
        } else{
            d = half + 1;
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("HAMMING.INP", "r", stdin);
    freopen("HAMMING.OUT", "w", stdout);
    generateHamming();
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i){
        ll a;
        cin >> a;
        ll result;
        result = findHamPos(a);
        if(result == -1){
            cout << "Not in sequence";
        } else{
            cout << result+1;
        }
        cout << "\n";
    }
    return 0;
}
