#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000000

ll n;
bool marked[maxN] = {};
string s;

string lm(){
    queue<pair<ll, string>> q;
    for(char x : s){
        string str = "";
        str.push_back(x);
        ll num = x - '0';
        q.push({num % n, str});
        marked[num % n] = true;
    }
    while(!q.empty() && q.front().first != 0){
        pair<ll, string> f = q.front();
        q.pop();
        ll mod = f.first;
        string str = f.second;
        for(int i = 0; i < s.size(); ++i){
            ll num = s[i] - '0';
            ll newMod = mod * 10 + num;
            newMod %= n;
            if(!marked[newMod]){
                q.push({newMod, str + s[i]});
                marked[newMod] = true;
            }
        }
    }
    if(q.empty()) return "0";
    return q.front().second;
}

int main(){
    freopen("LM.INP", "r", stdin);
    freopen("LM.OUT", "w", stdout);
    cin >> n >> s;
    string res;
    res = lm();
    cout << res;
    return 0;
}
