#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool validstr(string s) {
    vector<int> arr(26, 0);
    for(char c : s){
        arr[(int)c - 97] += 1;
    }
    for(int i = 0; i < arr.size(); ++i){
        while(arr[i] == 0 && i < arr.size()){
            arr.erase(arr.begin() + i);
        }
    }
    int validnum;
    int a = arr[0], b = arr[1], c = arr[2];
    if(a == b){
        validnum = a;
    } else if(b == c){
        validnum = b;
    } else if(a == c){
        validnum = a;
    } else{
        return false;
    }
    bool found = false;
    for(int i = 0; i < arr.size(); ++i){
        if(arr[i] == validnum){
            continue;
        } else{
            if(found == false && (abs(arr[i] - validnum) == 1 || arr[i] == 1)) {
                found = true;
            } else{
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("VALIDSTR.INP", "r", stdin);
    freopen("VALIDSTR.OUT", "w", stdout);
    string s;
    cin >> s;
    if(validstr(s)){
        cout << "YES";
    } else{
        cout << "NO";
    }
    return 0;
}
