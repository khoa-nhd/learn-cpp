#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100005

ll n;
ll a[maxN];
priority_queue<ll> d;
priority_queue<ll, vector<ll>, greater<ll>> c;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void medians(){
    d.push(a[0]);
    cout << a[0] << "\n";
    for(int i = 1; i < n; ++i){
        if(a[i] > d.top()){
            c.push(a[i]);
        } else{
            d.push(a[i]);
        }
        while((ll)d.size() - (ll)c.size() > 1){
            c.push(d.top());
            d.pop();
        }
        while((ll)c.size() - (ll)d.size() > 1){
            d.push(c.top());
            c.pop();
        }
        if(d.size() == c.size()){
            cout << d.top() << " " << c.top() << "\n";
        } else if(d.size() < c.size()){
            cout << c.top() << "\n";
        } else{
            cout << d.top() << "\n";
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MEDIANS.INP", "r", stdin);
    freopen("MEDIANS.OUT", "w", stdout);
    readData();
    medians();
    return 0;
}
