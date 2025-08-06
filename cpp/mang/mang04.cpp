// Cho n
// Hãy xem từ a1 đến an giá trị phân biệt nhỏ nhất và nhỏ nhì tìm được là bao nhiêu
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

int mang04(int id){
    int minn = -1;
    for(int i = 0; i < n; ++i){
        if(a[i] != id && (minn == -1 || a[i] < minn)){
            minn = a[i];
        }
    }
    return minn;
}

int main(){
    freopen("MANG04.INP", "r", stdin);
    freopen("MANG04.OUT", "w", stdout);
    readData();
    int min1 = mang04(-1), min2 = mang04(min1);
    cout<<min1<<" "<<min2;
    return 0;
}

