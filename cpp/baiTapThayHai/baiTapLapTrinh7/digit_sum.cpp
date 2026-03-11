#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string a, b;
ll h;

bool check(){
    vector<ll> hieu(b.size());
    string c;
    for(int i = 0; i < b.size() - a.size(); ++i){
        c.push_back('0');
    }
    c += a;
    for(int i = b.size() - 1; i >= 0; --i){
        ll sotru = c[i] - '0';
        ll sobitru = b[i] - '0';
        if(sobitru < sotru){
            sobitru += 10;
            b[i-1] = (b[i-1] - '0') - 1 + '0';
        }
        hieu[i] = sobitru - sotru;
    }
    ll res = 0;
    for(int i = 0; i < hieu.size(); ++i){
//        cout << hieu[i];
        if(hieu[i] != 0){
            for(int j = i; j < hieu.size(); ++j){
                res *= 10;
                res += hieu[j];
                if(res >= 9) break;
            }
            break;
        }
    }
    h = res;
    if(res >= 9) return true;
    return false;
}

void cong1(string &x){
    vector<ll> res(x.size()+1);
    ll carry = 1;
    for(int i = res.size() - 1; i > 0; --i){
        ll sohang = x[i-1] - '0' + carry;
        res[i] += sohang % 10;
        carry = sohang / 10;
    }
    res[0] = carry;
    string temp;
    for(ll i : res) temp.push_back(i + '0');
    x = temp;
}

ll mod9(string &x){
    ll res = 0;
    for(int i = 0; i < x.size(); ++i){
        res += x[i] - '0';
    }
    return res % 9;
}

int main(){
    freopen("DIGIT_SUM.INP", "r", stdin);
    freopen("DIGIT_SUM.OUT", "w", stdout);
    cin >> a >> b;
    if(check()){
        cout << 9;
    } else{
        ll res = 1;
        for(int i = 0; i <= h; ++i){
            res *= mod9(a);
            cong1(a);
        }
        if(res % 9 == 0) cout << 9;
        else cout << res % 9;
    }
//    cong1(a);
//    cout << a;
    return 0;
}
