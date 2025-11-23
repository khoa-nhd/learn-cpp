#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
ll n;

void binarygen(){
    for(int i = 0; i < n; ++i){
        if(s[i] == '0'){
            break;
        }
        if(i == n - 1){
            cout << -1;
            return;
        }
    }

    ll last1Idx = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] == '1'){
            last1Idx = i;
            break;
        }
    }

    for(int i = n - 1; i >= 0; --i){
        if(s[i] == '0' && i > last1Idx){
            s[i] = '1';
            for(int j = i+1; j < n; ++j){
                s[j] = '0';
            }
            cout << s;
            return;
        }
    }

    for(int i = 0; i < last1Idx - 1; ++i){
        cout << 0;
    }
    cout << 1;
    for(int i = last1Idx; i < n; ++i){
        cout << 0;
    }
}

int main(){
    freopen("BINARYGEN.INP", "r", stdin);
    freopen("BINARYGEN.OUT", "w", stdout);
    cin >> n;
    cin >> s;
    binarygen();
    return 0;
}
