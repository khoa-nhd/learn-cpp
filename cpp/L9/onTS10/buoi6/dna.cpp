#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

char a[] = {'A', 'T', 'G', 'C'};
char b[] = {'T', 'A', 'C', 'G'};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("i.INP", "r", stdin);
//    freopen("o.OUT", "w", stdout);
    string s;
    cin >> s;
    string res;
    for(char x : s){
        for(int i = 0; i < 4; ++i){
            if(x == a[i]) res.push_back(b[i]);
        }
    }
    reverse(res.begin(), res.end());
    cout << res;
    return 0;
}
