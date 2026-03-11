#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s, t;
vector<string> ss, tt;
string maxs, mins, maxt, mint;

bool lonHon(string &a, string &b){
    if(a.size() > b.size()) return true;
    return a > b;
}

void findMaxMin(string &x, string &maxVal, string &minVal){
    for(int i = 0; i < x.size(); ++i){
        string mot = x.substr(i, x.size()-i+1);
        string hai = x.substr(0, i-0);
        mot += hai;
        if(mot[0] == '0') continue;
        if(lonHon(mot, maxVal)) maxVal = mot;
        if(lonHon(minVal, mot) || minVal.size() == 0) minVal = mot;
    }
}

string tru(string &a, string &b){
    string c;
    for(int i = 0; i < a.size() - b.size(); ++i) c.push_back('0');
    c += b;
    vector<ll> res(a.size(), 0);
    ll r = 0;
    for(int i = a.size()-1; i >= 0; --i){
        int hieu = (a[i] - '0') - (c[i] - '0') - r;
        if (hieu < 0) {
            hieu += 10;
            r = 1;
        } else {
            r = 0;
        }
        res[i] = hieu;
    }
    string temp;
    for(int i = 0; i < res.size(); ++i){
        if(res[i] != 0){
            for(int j = i; j < res.size(); ++j){
                temp.push_back(res[j] +'0');
            }
            break;
        }
    }
    return temp;
}

void strshift(){
//    cout << maxs << " " << mins << "\n";
//    cout << maxt << " " << mint << "\n";
    string th1, th2;
    if(lonHon(maxs, mint)){
        th1 = tru(maxs, mint);
    }
    if(lonHon(maxt, mins)){
        th2 = tru(maxt, mins);
    }
    if(lonHon(th1, th2)) cout << th1;
    else cout << th2;
}

int main(){
    freopen("STRSHIFT.INP", "r", stdin);
    freopen("STRSHIFT.OUT", "w", stdout);
    cin >> s >> t;
    findMaxMin(s, maxs, mins);
    findMaxMin(t, maxt, mint);
    strshift();
    return 0;
}
