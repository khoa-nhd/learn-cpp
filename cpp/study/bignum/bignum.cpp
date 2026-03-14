#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> bigint;

bigint a, b;


void readData(){
    string x, y;
    cin >> x >> y;
    for(char i : x){
        a.push_back(i - '0');
    }
    for(char i : y){
        b.push_back(i - '0');
    }
}

bigint operator + (bigint x, bigint y){
    int i = 0, j = 0, cr = 0;
    bigint res;
    while(i < x.size() || j < y.size()){
        if(i < x.size()){
            cr += x[i];
            i += 1;
        }
        if(j < y.size()){
            cr += y[j];
            j += 1;
        }
        res.push_back(cr%10);
        cr /= 10;
    }
    if(cr > 0) res.push_back(cr);
    return res;
}

bigint operator - (bigint x, bigint y){
    int i = 0, j = 0, cr = 0;
    bigint res;
    while(i < x.size() || j < y.size()){
        int c = x[i] - cr;
        i += 1;
        if(j < y.size()){
            c -= y[j];
            j += 1;
        }
        if(c < 0){
            c += 10;
            cr = 1;
        } else{
            cr = 0;
        }
        res.push_back(c);
    }
   while(res.size() > 1 && res.back() == 0) res.pop_back();
    return res;
}

bigint operator * (bigint x, int y){
    bigint res;
    int cr = 0;
    for(int i = 0; i < x.size(); ++i){
        cr = cr + x[i] * y;
        res.push_back(cr%10);
        cr /= 10;
    }
    if(cr > 0) res.push_back(cr);
    return res;
}

bigint mul10(bigint x, int y){
    bigint res;
    for(int i = 0; i < y; ++i){
        res.push_back(0);
    }
    for(int i = 0; i < x.size(); ++i){
        res.push_back(x[i]);
    }
    return res;
}

bigint operator * (bigint x, bigint y){
    bigint res;
    for(int i = 0; i < y.size(); ++i){
        bigint c = x * y[i];
        c = mul10(c, i);
        res = res + c;
    }
    return res;
}

int cmp(bigint &x, bigint &y){
    if(x.size() > y.size()) return 1;
    if(x.size() < y.size()) return -1;
    for(int i = x.size() - 1; i >= 0; --i){
        if(x[i] > y[i]) return 1;
        if(x[i] < y[i]) return -1;
    }
    return 0;
}

void print(bigint res){
    for(int i = res.size() - 1; i >= 0; --i) cout << res[i];
    cout << "\n";
}

int main(){
    freopen("i.INP", "r", stdin);
    freopen("o.OUT", "w", stdout);
    readData();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    bigint res = a + b;
    print(res);
    res = a - b;
    print(res);
    res = a * b;
    print(res);
    return 0;
}
