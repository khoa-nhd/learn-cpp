#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
vector<ll> a;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        ll temp;
        cin >> temp;
        a.push_back(temp);
    }
}

ll kmin(){
    ll result = 1;
    sort(a.begin(), a.end());
    for(int i = 0; i < a.size()-1; ++i){
        if(a[i] > result){
            return result;
        } else if(a[i] < a[i+1]){
            result += 1;
        }
    }
    result = a.back() + 1;
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("KMIN.INP", "r", stdin);
    freopen("KMIN.OUT", "w", stdout);
    readData();
    ll m;
    m = kmin();
    cout << m;
    return 0;
}
