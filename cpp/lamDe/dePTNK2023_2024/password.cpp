#include <bits/stdc++.h>
using namespace std;

long long k;
long long pow10[19];

int getDigit(long long p){
    long long d = 1;
    long long cnt = 9*pow10[d-1];
    while(p > cnt * d){
        p -= cnt * d;
        d += 1;
        cnt = 9*pow10[d-1];
    }
    long long number = pow10[d - 1] + (p - 1) / d;
    int pos = (p - 1) % d;
    return (number / pow10[d - pos - 1]) % 10;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pow10[0] = 1;
    for(int i = 1; i < 19; i++) pow10[i] = pow10[i - 1] * 10;

    cin >> k;

    string ans = "";
    for(int i = 0; i < 4; i++){
        ans.push_back(char('0' + getDigit(k + i)));
    }

    cout << ans;
    return 0;
}
