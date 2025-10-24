#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n;
ll prefixA[maxN] = {}, prefixHxA[maxN] = {};
pair<ll, ll> input[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> input[i].second;
    }
    for(int i = 0; i < n; ++i){
        cin >> input[i].first;
    }
}

bool cmp(pair<ll, ll> a, pair<ll, ll> b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

void fly(){
    sort(input, input + n, cmp);
    prefixA[0] = input[0].first;
    prefixHxA[0] = input[0].first * input[0].second;
    for(int i = 1; i < n; ++i){
        prefixA[i] = prefixA[i - 1] + input[i].first;
        prefixHxA[i] = prefixHxA[i - 1] + input[i].first * input[i].second;
    }

    ll minEnergy = LLONG_MAX;
    ll minH;
    ll left, right;
    for(int i = 1; i < n-1; ++i){
        left = input[i].second*prefixA[i-1] - prefixHxA[i-1];
        right = (prefixHxA[n-1] - prefixHxA[i]) - input[i].second*(prefixA[n-1] - prefixA[i]);
        if(left + right < minEnergy){
            minEnergy = left + right;
            minH = input[i].second;
        }
    }
    right = (prefixHxA[n-1] - prefixHxA[0]) - input[0].second*(prefixA[n-1] - prefixA[0]);
    if(right < minEnergy){
        minEnergy = right;
        minH = input[0].second;
    }
    left = input[n-1].second*prefixA[n-1] - prefixHxA[n-1];
    if(left < minEnergy){
        minEnergy = left;
        minH = input[n-1].second;
    }

    cout << minH << " " << minEnergy;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("FLY.INP", "r", stdin);
    freopen("FLY.OUT", "w", stdout);
    readData();
    fly();
    return 0;
}
