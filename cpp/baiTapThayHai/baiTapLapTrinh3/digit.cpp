#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll k;
string s;

void readData(){
    cin >> s >> k;
}

void digit(){
    vector<int> a;
    a.push_back(0);
    k += 1;
    for(char x : s){
        int chuSo = x - '0';
        if(chuSo > a.back()&& k > 0 && a.size() > 0){
            while(chuSo > a.back()&& k > 0 && a.size() > 0){
                a.pop_back();
                k -= 1;
            }
            a.push_back(chuSo);
        } else{
            a.push_back(chuSo);
        }
    }
    while(k > 0){
        a.pop_back();
        k -= 1;
    }
    for(int i : a){
        cout << i;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("DIGIT.INP", "r", stdin);
    freopen("DIGIT.OUT", "w", stdout);
    readData();
    digit();
    return 0;
}
