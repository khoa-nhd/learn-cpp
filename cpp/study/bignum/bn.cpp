#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> bigint;

string c, d;
bigint a, b;

void readData(){
    cin >> c >> d;
    for(int i = c.size()-1; i >= 0; --i){
        a.push_back(c[i] - '0');
    }
    for(int i = d.size()-1; i >= 0; --i){
        b.push_back(d[i] - '0');
    }
}

void print(bigint x){
    for(int i = x.size() - 1; i >= 0; --i){
        cout << x[i];
    }
    cout << "\n";
}

bigint operator + (bigint &x, bigint &y){
    bigint res;
    ll cr = 0;
    ll i = 0, j = 0;
    while(i < x.size() || j < y.size()){
        if(i < x.size()) cr += x[i++];
        if(j < y.size()) cr += y[j++];
        res.push_back(cr % 10);
        cr /= 10;
    }
    if(cr > 0) res.push_back(cr);
    return res;
}

bool operator > (bigint &x, bigint &y){
    if(x.size() != y.size()) return x.size() > y.size();
    ll i = x.size() - 1;
    while(i >= 0){
        if(x[i] != y[i]) return x[i] > y[i];
        i -= 1;
    }
    return false;
}

bigint operator - (bigint &x, bigint &y){
    bigint res;
    ll m = 0;
    ll i = 0, j = 0;
    while(i < x.size() || j < y.size()){
        ll v = x[i++] - m;
        if(j < y.size()) v -= y[j++];
        m = (v < 0);
        if(v < 0) v += 10;
        res.push_back(v);
    }
    while(res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}

bigint operator * (bigint &x, int y){
    bigint res;
    ll cr = 0;
    for(int i = 0; i < x.size(); ++i){
        cr += x[i] * y;
        res.push_back(cr % 10);
        cr /= 10;
    }
    while(cr > 0){
        res.push_back(cr % 10);
        cr /= 10;
    }
    return res;
}

bigint mu10(bigint &x, ll somu){
    bigint res;
    for(int i = 0; i < somu; ++i) res.push_back(0);
    for(int i = 0; i < x.size(); ++i) res.push_back(x[i]);
    return res;
}

bigint operator * (bigint &x, bigint &y){
    bigint res;
    for(int i = 0; i < y.size(); ++i){
        bigint t1 = x * y[i];
        bigint t2 = mu10(t1, i);
        res = res + t2;
    }
    return res;
}

bigint operator / (bigint &x, int y){
    bigint res;
    ll num = 0;
    for(int i = x.size() - 1; i >= 0; --i){
        num *= 10;
        num += x[i];
        res.push_back(num / y);
        num = num % y;
    }
    reverse(res.begin(), res.end());
    while(res.back() == 0) res.pop_back();
    return res;
}

bigint operator / (bigint &x, bigint &y){
    bigint res;
    bigint d(1, 0);
    bigint c = x;
    bigint mot(1, 1);
    while(c > d || d == c){
        bigint half = d + c;
        half = half / 2;
        bigint t = half * y;
        if(t > x) c = half - mot;
        else{
            d = half + mot;
            res = half;
        }
    }
    return res;
}

int main(){
    freopen("i.INP", "r", stdin);
    freopen("o.OUT", "w", stdout);
    readData();
    bigint res;
    res = a + b;
    print(res);
    res = a - b;
    print(res);
    res = a * b;
    print(res);
    res = a / b;
    print(res);
    return 0;
}
