#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

ll n, a[maxN] = {};
pair<ll, ll> firstLast[1005] = {};
ll prefixSum[maxN] = {};

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll quantrong(){
    for(int i = 0; i < 1005; ++i){
        firstLast[i].first = -1;
    }
    for(int i = 0; i < n; ++i){
        if(firstLast[a[i]].first == -1){
            firstLast[a[i]].first = i;
        }
        firstLast[a[i]].second = i;
    }
    prefixSum[0] = a[0];
    for(int i = 1; i < n; ++i){
        prefixSum[i] = prefixSum[i-1] + a[i];
    }

    ll maxx = LLONG_MIN;
    for(int i = 0; i < 1005; ++i){
        if(firstLast[i].first != -1){
            ll start = firstLast[i].first;
            ll endd = firstLast[i].second;
            ll sum = prefixSum[endd] - prefixSum[start-1];
            if(sum > maxx){
                maxx = sum;
            }
        }
    }
    return maxx;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readData();
    ll res;
    res = quantrong();
    cout << res;
    return 0;
}
