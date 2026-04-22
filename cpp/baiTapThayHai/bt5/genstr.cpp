#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
bool used[8] = {};
set<string> res;

void genstr(string str){
    if(str.size() == s.size()){
        res.insert(str);
        return;
    }
    for(int i = 0; i < s.size(); ++i){
        if(!used[i]){
            used[i] = true;
            str.push_back(s[i]);
            genstr(str);
            str.pop_back();
            used[i] = false;
        }
    }
}

int main(){
    freopen("GENSTR.INP", "r", stdin);
    freopen("GENSTR.OUT", "w", stdout);
    cin >> s;
    genstr("");
    cout << res.size() << "\n";
    for(string x : res){
        cout << x << "\n";
    }
    return 0;
}
