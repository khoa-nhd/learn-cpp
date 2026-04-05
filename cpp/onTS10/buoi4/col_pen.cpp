#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

set<ll> s;

int main(){
    for(int i = 0; i < 4; ++i){
        ll temp = 0;
        cin >> temp;
        s.insert(temp);
    }
    cout << 4 - s.size();
    return 0;
}
