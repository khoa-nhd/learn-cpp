#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;

bool ngoacMo(char x){
    return (x == '(' || x == '[' || x == '{');
}

bool cungLoai(char x, char y){
    if(x == '(') return (y == ')');
    if(x == '{') return (y == '}');
    if(x == '[') return (y == ']');
    return false;
}

bool checkExist(ll k){
    string str;
    for(int i = k; i < s.size(); ++i){
        str.push_back(s[i]);
    }
    for(int i = 0; i < k; ++i){
        str.push_back(s[i]);
    }

    stack<char> stk;
    for(int i = 0; i < str.size(); ++i){
       if(!ngoacMo(str[i])){
            if(stk.empty()) return false;
            if(cungLoai(stk.top(), str[i])){
                stk.pop();
            } else{
                stk.push(str[i]);
            }
       } else{
            stk.push(str[i]);
       }
    }
    return stk.empty();
}

bool brackets(){
    for(int k = 0; k <= s.size(); ++k){
        if(checkExist(k)) return true;
    }
    return false;
}

int main(){
    freopen("BRACKETS.INP", "r", stdin);
    freopen("BRACKETS.OUT", "w", stdout);
    cin >> s;
    bool res;
    res = brackets();
    if(res) cout << "YES";
    else cout << "NO";
    return 0;
}
