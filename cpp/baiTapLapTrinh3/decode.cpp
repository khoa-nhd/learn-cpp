#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string input;
map<string, int> a;


/*string decode(){
    int prev = 0;
    string result = "";
    int i = 0;
    int n = input.size();
    while(i < n){
        bool hople = false;
        for(int len = 1; len <= 3; ++len){
            if(i + len <= n){
                string sub = input.substr(i, len);
                if(a.count(sub)){
                    result += char('0' + a[sub]);
                    hople = true;
                    i += len;
                    break;
                }
            }
        }
        if(!hople){
            return "-1";
        }
    }
    return result;
}*/

void decode(){
    vector<int> result;
    vector<string> mystack;
    int i = 0;
    int n = input.size();
    while(i < n){
        bool hople = false;
        for(int len = 1; len <= 3; ++len){
            if(i + len <= n){
                string sub = input.substr(i, len);
                if(a.count(sub)){
                    result.push_back(a[sub]);
                    mystack.push_back(sub);
                    hople = true;
                    i += len;
                    break;
                }
            }
        }
        if(!hople){
            while(mystack.size() > 0){
                if(mystack.back().size() == 1){
                    i -= mystack.back().size();
                    mystack.pop_back();
                    result.pop_back();
                    string sub2 = input.substr(i, 3);
                    if(a.count(sub2)){
                        result.push_back(a[sub2]);
                        mystack.push_back(sub2);
                        i += 3;
                        break;
                    }
                } else{
                    i -= mystack.back().size();
                    mystack.pop_back();
                    result.pop_back();
                }
            }
            if(mystack.size() == 0){
                cout << -1;
                return;
            }
        }
    }

    for(int i = 0; i < result.size(); ++i){
        cout << result[i];
    }
}





int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("DECODE.INP", "r", stdin);
    freopen("DECODE.OUT", "w", stdout);
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
    decode();
    return 0;
}
