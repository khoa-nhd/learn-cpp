#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n, k, a[maxN];
ll pre[maxN] = {};
unordered_map<ll, ll> myMap;

void readData(){
    cin >> n >> k;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void cubics(){
    pre[0] = 0; // trường hợp mảng bắt đầu từ 0
    for(int i = 1; i <= n; ++i){
        pre[i] = pre[i-1] + a[i-1];
    }
    for(int i = 0; i <= n; ++i){
        pre[i] -= k*i;
//        cout << pre[i] << " ";
    }
//    cout << "\n";

//    myMap[0] = 0; // trường hợp dãy bắt đầu từ 0;
    ll maxlen = LLONG_MIN;
    ll start;
    for(int i = 0; i <= n; ++i){
        if(myMap.find(pre[i]) != myMap.end()){
            if(maxlen < i - myMap[pre[i]]){
                maxlen = i - myMap[pre[i]];
                start = myMap[pre[i]];
            }
        } else{
            myMap[pre[i]] = i;
        }
    }
    if(maxlen != LLONG_MIN){
        cout << maxlen << " " << start+1;
    } else{
        cout << 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CUBICS.INP", "r", stdin);
    freopen("CUBICS.OUT", "w", stdout);
    readData();
    cubics();
    return 0;
}
