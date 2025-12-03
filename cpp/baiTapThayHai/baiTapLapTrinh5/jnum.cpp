#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll t, n;

void jnum(){
    queue<ll> q;
    for(int i = 0; i < 10; ++i) q.push(i);
    while(q.front() <= n){
        ll f = q.front();
        q.pop();
        cout << f << " ";
        ll lastVal = f % 10;
        f *= 10;
        if(f != 0){
            if(lastVal != 0) q.push(f + (lastVal - 1));
            if(lastVal != 9) q.push(f + (lastVal + 1));
        }
    }
    cout << "\n";
}

int main(){
    freopen("JNUM.INP", "r", stdin);
    freopen("JNUM.OUT", "w", stdout);
    cin >> t;
    for(int i = 0; i < t; ++i){
        cin >> n;
        jnum();
    }
    return 0;
}
