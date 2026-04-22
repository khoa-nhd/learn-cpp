#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string a, b;
vector<string> dayVongB;

void genDayVong(){
    for(int i = 0; i < b.size(); ++i){
        string neww = b.substr(i, b.size() - i);
        neww += b.substr(0, i);
        dayVongB.push_back(neww);
    }
}

bool checkDayVong(string &sub){
    for(int i = 0; i < dayVongB.size(); ++i){
        if(sub == dayVongB[i]) return true;
    }
    return false;
}

ll strings(){
    ll res = 0;
    for(int i = 0; i + b.size() - 1 < a.size(); ++i){
        string sub = a.substr(i, b.size());
        if(checkDayVong(sub)) res += 1;
    }
    return res;
}

int main(){
    freopen("STRINGS.INP", "r", stdin);
    freopen("STRINGS.OUT", "w", stdout);
    cin >> a >> b;
    genDayVong();
    ll res = strings();
    cout << res;
    return 0;
}
