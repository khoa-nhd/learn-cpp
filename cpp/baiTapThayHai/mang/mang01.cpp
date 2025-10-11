// Cho n, x
// Hãy xem từ a1 đến an có bao nhiêu phần tử là ước của x
#include <iostream>
#include <cstdio>
using namespace std;
#define maxN 1000000

int a[maxN], n, x;

void readData(){
    cin>>n>>x;
    for(int i = 0; i < n; ++i){
        cin>>a[i];
    }
}

int mang01(){
    int s = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] != 0 && x%a[i] == 0){
            s = s + 1;
        }
    }
    return s;
}

int main(){
    freopen("MANG01.INP", "r", stdin);
    freopen("MANG01.OUT", "w", stdout);
    int m;
    readData();
    m = mang01();
    cout<<m;
    return 0;
}
