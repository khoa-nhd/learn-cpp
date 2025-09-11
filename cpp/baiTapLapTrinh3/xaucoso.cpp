#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string a, b;
bool laXauCoSo = false;

void readData(){
    cin >> a >> b;
}

string timXauCoSo(string s){
    string base, coSo;
    laXauCoSo = false;
    for(int i = 1; i < s.size(); ++i){
        base = s.substr(0, i);
        for(int j = 0; j < s.size(); j += i){
            string k = s.substr(j, i);
            if(k != base){
                break;
            } else{
                coSo = base;
                laXauCoSo = true;
                return coSo;
            }
        }
    }
    return coSo;
}

string uclnxaucoso(string xauCoSo){
    ll d1 = a.size() / xauCoSo.size();
    ll d2 = b.size() / xauCoSo.size();
    ll ucln = gcd(d1, d2);
    for(int i = 0; i < ucln; ++i){
        xauCoSo += xauCoSo;
    }
    return xauCoSo;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("i.INP", "r", stdin);
    freopen("o.OUT","w", stdout);
    readData();
    string aa = timXauCoSo(a);
    if(!laXauCoSo){
        cout << "NO";
        return 0;
    }
    string bb = timXauCoSo(b);
    if(!laXauCoSo){
        cout << "NO";
        return 0;
    }
    if(bb != aa){
        cout << "NO";
        return 0;
    } else{
        string result;
        result = uclnxaucoso(aa);
        cout << result;
    }
    return 0;
}
