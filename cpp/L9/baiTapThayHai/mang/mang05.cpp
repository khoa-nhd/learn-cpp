// Cho n
// Hãy xem từ a1 đến an vị trí của giá trị nhỏ nhất và nhỏ nhì tìm được là gì
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

int mang05(int id){
    int minn = -1, pos = 0;
    for(int i = 0; i < n; ++i){
        if(i != id && (minn == -1 || a[i] < minn)){
            minn = a[i];
            pos = i;
        }
    }
    return pos;
}

int main(){
    freopen("MANG05.INP", "r", stdin);
    freopen("MANG05.OUT", "w", stdout);
    readData();
    int min1 = mang05(-1), min2 = mang05(min1);
    cout<<min1+1<<" "<<min2+1;
    return 0;
}

