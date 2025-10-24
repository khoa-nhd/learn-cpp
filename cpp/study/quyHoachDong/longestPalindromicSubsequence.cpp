#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 1000

string s = "abcdefghijklmnopqrstuvwxyzzyx";
ll dem = 0;
ll a2chieu[maxN][maxN] = {};

ll cach1(ll d, ll c){
    dem += 1;
    if(d > c){
        return 0;
    }
    if(d == c){
        return 1;
    }
    if(s[d] == s[c]){
        return cach1(d + 1, c - 1) + 2;
    } else{
        return max(cach1(d + 1, c), cach1(d, c - 1));
    }
}

void cach2(){
    for(int i = 1; i < s.size(); ++i){
        a2chieu[i][i+1] = 1;
    }
    for(int i = 0; i < s.size(); ++i){
        for(int j =  i + 2; j <= s.size(); ++j){
            if(s[i] == s[i + j]){
                a2chieu[i][j] = [i+1][j-1] + 2;
            } else{
                a2chieu[i][j] = max(a2chieu[i][j-1], a2chieu[i+1][j]);
            }
        }
    }
    cout << a2chieu[s.si]
}

int main(){
//    ll one = cach1(0, s.size()-1);
//    cout << one << " " << dem;
    return 0;
}
