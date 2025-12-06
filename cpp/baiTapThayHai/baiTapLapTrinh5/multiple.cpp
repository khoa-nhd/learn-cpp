#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 10005

string mul[maxN] = {};

string multiple(ll n){
    vector<bool> marked(n, false);
    queue<pair<ll, string>> q;
    marked[1] = true;
    q.push({1 % n, "1"});
    while(q.front().first != 0){
        pair<ll, string> f = q.front();
        q.pop();
        string str = f.second;
        ll x = f.first * 10;
        x %= n;
        if(!marked[x]){
            marked[x] = true;
            q.push({x, str + '0'});
        }
        x += 1;
        x %= n;
        if(!marked[x]){
            marked[x] = true;
            q.push({x, str + '1'});
        }
    }
    string res = q.front().second;
    return q.front().second;
}

void genMultiple(){
    for(int i = 1; i < maxN; ++i){
        string temp;
        temp = multiple(i);
        mul[i] = temp;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MULTIPLE.INP", "r", stdin);
    freopen("MULTIPLE.OUT", "w", stdout);
    ll n = 1;
//    genMultiple();
    while(true){
        cin >> n;
        if(n == 0) break;
//        string res = mul[n];
        string res = multiple(n);
        cout << res << "\n";
    }
    return 0;
}
