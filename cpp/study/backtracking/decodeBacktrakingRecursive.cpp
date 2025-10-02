#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string input;
vector<int> result;
map<string, int> a;

bool decode(int idx){
    if(idx == input.size()){
        return true;
    }
    for(int i = 1; i <= 3; ++i){
        string sub = input.substr(idx, i);
        if(a.count(sub)){
            bool xet = decode(idx+i);
            if(xet){
                result.push_back(a[sub]);
                return true;
            }
        }
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("i.INP", "r", stdin);
    freopen("o.OUT", "w", stdout);
    cin >> input;
    a["a"] = 1;
    a["b"] = 2;
    a["cc"] = 3;
    a["bbc"] = 4;
    a["cbc"] = 5;
    a["abc"] = 6;
    a["bac"] = 7;
    a["aac"] = 8;
    a["cac"] = 9;
    bool m = decode(0);
    if(m){
        for(int i = result.size()-1; i >= 0; --i){
            cout << result[i];
        }
    } else{
        cout << -1;
    }
    return 0;
}
