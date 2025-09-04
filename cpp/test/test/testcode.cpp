#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

set<ll> hammingset;
vector<ll> hammingvec;

void generateHamming(){
    ll i = 1, j = 1, k = 1;
    //ll maxx = 1000000000000000000;
    ll maxx = 100;
    while(i*j*k < maxx){
        while(i*j*k < maxx){
            while(i*j*k < maxx){
                hammingset.insert(i*j*k);
                k *= 5;
            }
            k = 1;
            j *= 3;
        }
        j = 1;
        k = 1;
        i *= 2;
    }
    for(ll value : hammingset){
        hammingvec.push_back(value);
    }
}

ll findHamPos(ll target){
    ll d = 0, c = hammingvec.size();
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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
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
