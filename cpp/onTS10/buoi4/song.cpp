#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll in[10];

int main(){
    for(int i = 0; i < 8; ++i){
        cin >> in[i];
    }
    bool a = false;
    bool d = false;
    for(int i = 1; i < 8; ++i){
        if(in[i-1] < in[i]) a = true;
        if(in[i-1] > in[i]) d = true;
    }
    if(a && d) cout << "MIXED";
    else if(a) cout << "ASCENDING";
    else cout << "DESCENDING";
    return 0;
}
