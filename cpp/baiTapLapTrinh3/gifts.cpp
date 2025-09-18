#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> a;
vector<ll> b;

void readData(){
    ll temp;
    while(cin >> temp){
        a.push_back(temp);
    }
}

bool mySearch(int d, int c, ll target){
    while(d <= c){
        ll half = (d+c)/2;
        if(b[half] == target){
            return true;
        }
        if(b[half] < target){
            d = half + 1;
        } else{
            c = half - 1;
        }
    }
    return false;
}

ll gifts(){
    ll result = 0;
    ll n = a.size();
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            ll temp = a[i] + a[j];
            b.push_back(temp);
        }
    }
    sort(b.begin(), b.end());
    for(int i = 0; i < n; ++i){
        if(mySearch(0, b.size()-1, a[i]*2)){
            result += 1;
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("GIFTS.INP", "r", stdin);
    freopen("GIFTS.OUT", "w", stdout);
    readData();
    ll m;
    m = gifts();
    cout << m;
    return 0;
}
