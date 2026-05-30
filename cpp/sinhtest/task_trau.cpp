#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> bignum;

void EraseZero(bignum & num){
    while(num.size() > 1 && num.back() == 0) num.pop_back();
}

bignum GetNum(string s){
    bignum ans;
    for(int i = s.size() - 1; i >= 0; --i){
        ans.push_back(s[i] - '0');
    }
    EraseZero(ans);
    return ans;
}

void PrintNum(bignum num){
    for(int i = num.size() - 1; i >= 0; --i){
        cout << num[i];
    }
    cout << "\n";
}

bignum operator + (bignum a, bignum b){
    bignum ans;
    int carry = 0;
    int i = 0;
    while(i < a.size() || i < b.size() || carry){
        int curr = carry;
        if(i < a.size()) curr += a[i];
        if(i < b.size()) curr += b[i];
        ans.push_back(curr % 10);
        carry = curr / 10;
        ++i;
    }
    return ans;
}

bool operator > (bignum a, bignum b){
    if(a.size() != b.size()) return a.size() > b.size();
    for(int i = a.size() - 1; i >= 0; --i){
        if(a[i] != b[i]) return a[i] > b[i];
    }
    return 0;
}

bool operator < (bignum a, bignum b){
    if(a.size() != b.size()) return a.size() < b.size();
    for(int i = a.size() - 1; i >= 0; --i){
        if(a[i] != b[i]) return a[i] < b[i];
    }
    return 0;
}

bool operator == (bignum a, bignum b){
    if(a.size() != b.size()) return 0;
    for(int i = a.size() - 1; i >= 0; --i){
        if(a[i] != b[i]) return 0;
    }
    return 1;
}

bignum operator - (bignum a, bignum b){
    bignum ans;
    if(a < b){
        cout << "-";
        return ans;
    }
    int borrow = 0;
    for(int i = 0; i < a.size(); ++i){
        int curr = a[i] - borrow;
        if(i < b.size()) curr -= b[i];
        if(curr < 0){
            curr += 10;
            borrow = 1;
        }else{
            borrow = 0;
        }
        ans.push_back(curr);
    }
    EraseZero(ans);
    return ans;
}

bignum operator * (bignum a, int b){
    bignum ans;
    int carry = 0;
    int i = 0;
    while(i < a.size() || carry){
        int curr = (i < a.size() ? a[i] * b : 0) + carry;
        ans.push_back(curr % 10);
        carry = curr / 10;
        ++i;
    }
    EraseZero(ans);
    return ans;
}

bignum mu10(bignum num, int k){
    bignum ans(k, 0);
    for(int i = 0; i < num.size(); ++i) ans.push_back(num[i]);
    return ans;
}

bignum operator * (bignum a, bignum b){
    bignum ans;
    for(int i = 0; i < b.size(); ++i){
        bignum curr = mu10(a, i);
        curr = curr * b[i];
        ans = ans + curr;
    }
    EraseZero(ans);
    return ans;
}

bignum operator / (bignum a, int b){
    bignum ans;
    if(b == 0){
        cout << "-";
        return ans;
    }
    int carry = 0;
    for(int i = a.size() - 1; i >= 0; --i){
        carry *= 10;
        carry += a[i];
        ans.push_back(carry / b);
        carry -= (b * (carry / b));
    }
    reverse(ans.begin(), ans.end());
    EraseZero(ans);
    return ans;
}

bignum operator / (bignum a, bignum b){
    bignum ans(1, 0), l(1, 0), r = a;
    while(l < r || l == r){
        bignum m = (l + r) / 2;
        bignum one(1, 1);
        if(m * b < a || m * b == a){
            l = m + one;
            ans = m;
        }else{
            r = m - one;
        }
    }
    EraseZero(ans);
    return ans;
}

bignum operator % (bignum a, bignum b){
    bignum ans;
    ans = (a - (a / b) * b);
    EraseZero(ans);
    return ans;
}

void sol(){
    string a, b;
    cin >> a >> b;
    bignum num1 = GetNum(a), num2 = GetNum(b);
    PrintNum(num1 + num2);
    PrintNum(num1 - num2);
//    PrintNum(num1 * 0);
    PrintNum(num1 * num2);
//    PrintNum(num1 / 0);
    PrintNum(num1 / num2);
//    PrintNum(num1 % num2);
//    cout << (num1 < num2) << "\n";
//    cout << (num1 == num2) << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("i.inp", "r", stdin);
    freopen("o.ans", "w", stdout);
    sol();
    return 0;
}
