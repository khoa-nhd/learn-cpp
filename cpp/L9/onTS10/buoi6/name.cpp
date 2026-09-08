#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
ll n;
char thuong[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char hoa[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

void sol(){
    string res;
    ll bd = 0;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] != ' '){
            bd = i;
            break;
        }
    }
    for(int i = bd; i < s.size(); ++i){
        if(s[i] == ' '){
            if(res.back() != ' ') res.push_back(' ');
        } else if(res.size() == 0 || res.back() == ' '){
            for(int j = 0; j < 26; ++j){
                if(s[i] == thuong[j]){
                    res.push_back(hoa[j]);
                    break;
                }
                if(j == 25) res.push_back(s[i]);
            }
        } else{
            for(int j = 0; j < 26; ++j){
                if(s[i] == hoa[j]){
                    res.push_back(thuong[j]);
                    break;
                }
                if(j == 25) res.push_back(s[i]);
            }
        }
    }
    if(res.back() == ' ') res.pop_back();
    cout << res << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    cin >> n;
    cin.ignore();
    for(int i = 0; i < n; ++i){
        getline(cin, s);
        sol();
//        cout << s << "\n";
    }
    return 0;
}
