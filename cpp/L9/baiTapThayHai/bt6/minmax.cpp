#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string c, d;

string findmin(){
    string a = c;
    string b = d;
    string res;
    while(a.size() >= 0 && b.size() >= 0){
        if(a.size() == 0){
            res += b;
            break;
        } else if(b.size() == 0){
            res += a;
            break;
        } else{
            if(a + b < b + a){
                res.push_back(a[0]);
                a.erase(0, 1);
            } else{
                res.push_back(b[0]);
                b.erase(0, 1);
            }
        }
    }
    return res;
}

string findmax(){
    string a = c;
    string b = d;
    string res;
    while(a.size() >= 0 && b.size() >= 0){
        if(a.size() == 0){
            res += b;
            break;
        } else if(b.size() == 0){
            res += a;
            break;
        } else{
            if(a + b > b + a){
                res.push_back(a[0]);
                a.erase(0, 1);
            } else{
                res.push_back(b[0]);
                b.erase(0, 1);
            }
        }
    }
    return res;
}

int main(){
    freopen("MINMAX.INP", "r", stdin);
    freopen("MINMAX.OUT", "w", stdout);
    cin >> c >> d;
    cout << findmin() << "\n" << findmax();
    return 0;
}
