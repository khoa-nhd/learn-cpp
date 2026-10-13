#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
string s;
bool kytu[30] = {};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("STRGAME.INP", "r", stdin);
    freopen("STRGAME.OUT", "w", stdout);
    cin >> n >> s;
    for(int i = 0; i < n; ++i){
        kytu[s[i] - 'a'] = true;
    }
    int cnt = 0;
    for(int i = 0; i < 30; ++i){
        cnt += kytu[i];
    }
    if(cnt % 2 == 1){
        cout << "SECOND";
    } else{
        cout << "FIRST";
    }
    return 0;
}
