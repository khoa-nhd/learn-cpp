#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000

int a[maxN] = {}, n, i = 0;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void brackets(int b, int pos){
    if(i >= n){
        return;
    }
    if(b == 0){
        cout << "()";
        i += 1;
    } else{
        cout << "(";
        i += 1;
        while(i <= b/2 + pos){
            brackets(a[i], i);
        }
        cout << ")";
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BRACKETS.INP", "r", stdin);
    freopen("BRACKETS.OUT", "w", stdout);
    readData();
    for(i = 0; i < n; i){
        brackets(a[i], i);
    }
    return 0;
}
