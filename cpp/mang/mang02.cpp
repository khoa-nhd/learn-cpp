// Cho n
// Hãy xem từ a1 đến an độ lệch nhỏ nhất tìm được là bao nhiêu
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define maxN 1000000

int a[maxN], n;

void readData(){
    cin>>n;
    for(int i = 0; i < n; ++i){
        cin>>a[i];
    }
}

int mang02(){
    int minDif = 10000000;
    for(int i = 0; i < n-1; ++i){
        if(abs(a[i]-a[i+1]) < minDif){
            minDif = abs(a[i]-a[i+1]);
        }
    }
    return minDif;
}

int main(){
    freopen("MANG02.INP", "r", stdin);
    freopen("MANG02.OUT", "w", stdout);
    int m;
    readData();
    m = mang02();
    cout<<m;
    return 0;
}

