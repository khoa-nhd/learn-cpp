#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool checkpal(string s){
    ll arr[26] = {};
    for(char c : s){
        arr[(int)c - 97] += 1;
    }
    bool found = false;
    if(s.size()%2 == 0){
        for(int i = 0; i < 26; ++i){
            if(arr[i]%2 == 1){
                return false;
            }
        }
    } else{
        for(int i = 0; i < 26; ++i){
            if(arr[i]%2 == 0){
                continue;
            } else{
                if(found == false){
                    found = true;
                } else{
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CHECKPAL.INP", "r", stdin);
    freopen("CHECKPAL.OUT", "w", stdout);
    string s;
    cin >> s;
    if(checkpal(s)) {
        cout << "YES";
    } else{
        cout << "NO";
    }
    return 0;
}
