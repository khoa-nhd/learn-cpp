#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
vector<int> v;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        char c;
        cin >> c;
        v.push_back(c - '0');
    }
}

void sol(){
    deque<int> dq;
    for(int i = 0; i < n; ++i) dq.push_back(v[i]);
    for(int i = 0; i < 10; ++i){
        for(int j = 0; j < n; ++j){
            v[j] += 1;
            v[j] %= 10;
        }
        deque<int> ndq;
        for(int i = 0; i < n; ++i){
            ndq.push_back(v[i]);
        }
        if(ndq < dq) dq = ndq;
        for(int i = 0; i < n; ++i){
            ndq.push_front(ndq.back());
            ndq.pop_back();
            if(ndq < dq) dq = ndq;
        }
    }
    for(int i = 0; i < dq.size(); ++i) cout << dq[i];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("LOCK.INP", "r", stdin);
    freopen("LOCK.OUT", "w", stdout);
    readData();
    sol();
    return 0;
}
