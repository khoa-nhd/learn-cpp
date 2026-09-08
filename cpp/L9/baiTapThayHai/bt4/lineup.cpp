#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

ll n, h[maxN] = {}, sorted[maxN] = {};
unordered_map<ll, ll> longestOrderedSequence;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
       cin >> h[i];
       sorted[i] = h[i];
    }
}

ll mysearch(int d, int c, ll target){
    while(d <= c){
        ll half = (d + c) / 2;
        if(sorted[half] == target){
            return half;
        }
        if(sorted[half] > target){
            c = half - 1;
        } else{
            d = half + 1;
        }
    }
    return -1;
}

ll lineup(){
    sort(sorted, sorted + n);
    ll maxx = LLONG_MIN;
    for(int i = 0; i < n; ++i){
        ll index = mysearch(0, n-1, h[i]);
        if(index != 0){
            if(longestOrderedSequence.find(sorted[index-1]) != longestOrderedSequence.end()){
                maxx = max(longestOrderedSequence[sorted[index-1]] + 1, maxx);
                longestOrderedSequence[sorted[index]] = longestOrderedSequence[sorted[index-1]];
            }
        }
        longestOrderedSequence[sorted[index]] += 1;
//        cout << sorted[index] << " ";
    }
//    cout << "\n";
//    for(pair<ll, ll> x : longestOrderedSequence){
//        cout << x.second << " ";
//    }
//    cout << "\n";
    if(maxx == LLONG_MIN) return n - 1;
    return n - maxx;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("LINEUP.INP", "r", stdin);
    freopen("LINEUP.OUT", "w", stdout);
    readData();
    ll result;
    result = lineup();
    cout << result;
    return 0;
}
