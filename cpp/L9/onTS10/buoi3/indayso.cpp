#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll freq[100000] = {};
ll n, k;

void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        ll temp;
        cin >> temp;
        freq[temp] += 1;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readData();
    vector<ll> res;
    for(int i = 0; i < 200; ++i){
        if(freq[i] >= k) res.push_back(i);
    }
    if(res.size() == 0) cout << "NO";
    else{
        for(int i = 0; i < res.size(); ++i){
            cout << res[i] << " ";
        }
    }
    return 0;
}
