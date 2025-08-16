#include <cstdio>
#include <iostream>
using namespace std;
#define maxN 1000000

int a[maxN], n;

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

void sgame(){
    long long chan = 0, le = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] % 2 == 0){
            chan = chan + (n - i);
        } else{
            le = le + (n - i);
        }
    }
    cout << chan << " " << le;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SGAME.INP", "r", stdin);
    freopen("SGAME.OUT", "w", stdout);
    readData();
    sgame();
    return 0;
}
