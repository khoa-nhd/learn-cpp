#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
string x, y;

void chia2(string &k){
    bool du = false;
    string res;
    for(int i = 0; i < k.size(); ++i){
        ll sochia = 0;
        if(du) sochia = 10;
        ll them = k[i] - '0';
        sochia += them;
        if(sochia % 2 == 0) du = false;
        else du = true;
        sochia /= 2;
        res.push_back(sochia + '0');
    }
    string temp;
    for(int i = 0; i < res.size(); ++i){
        if(res[i] != '0'){
            for(int j = i; j < res.size(); ++j){
                temp.push_back(res[j]);
            }
            break;
        }
    }
    k = temp;
}

void nhan2(string &k){
    vector<ll> res(k.size()+1, 0);
    for(int i = k.size() - 1; i >= 0; --i){
        res[i+1] += ((k[i] - '0') * 2) % 10;
        res[i] += ((k[i] - '0') * 2) / 10;
    }
    string temp;
    if(res[0] >= 0) temp.push_back(res[0] + '0');
    for(int i = 1; i < res.size(); ++i){
        temp.push_back(res[i] + '0');
    }
    k = temp;
}

void tru(string &a, string &b){
    vector<ll> res(a.size(), 0);
    string c;
    for(int i = 0; i < a.size() - b.size(); ++i){
        c.push_back('0');
    }
    for(int i = 0; i < b.size(); ++i){
        c.push_back(b[i]);
    }
    for(int i = a.size() - 1; i >= 0; --i){
        if(a[i] < c[i]){
            a[i-1] = ((a[i-1] - '0') - 1) + '0';
            ll sotru = 10 + (a[i] - '0');
            res[i] = sotru - (c[i] - '0');
        } else{
            res[i] = (a[i] - '0') - (c[i] - '0');
        }
    }
    string temp;
    for(int i = 0; i < res.size(); ++i){
        if(res[i] != 0){
            for(int j = i; j < res.size(); ++j){
                temp.push_back(res[j] + '0');
            }
            break;
        }
    }
    a = temp;
}

void reg_coor(){
    string canh;
    canh.push_back('1');
    for(int i = 0; i < n; ++i){
        nhan2(canh);
    }
    chia2(canh);
    string res;
    res.push_back('t');
    while(x != canh && y != canh){
        if(x > canh && y > canh){
            res.push_back('r');
            tru(x, canh);
            tru(y, canh);
        } else if(x < canh && y > canh){
            res.push_back('q');
            tru(y, canh);
        } else if(x > canh && y < canh){
            res.push_back('s');
            tru(x, canh);
        } else{
            res.push_back('t');
        }
        chia2(canh);
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("REG_COOR.INP", "r", stdin);
    freopen("REG_COOR.OUT", "w", stdout);
    cin >> n >> x >> y;
    reg_coor();
    return 0;
}
