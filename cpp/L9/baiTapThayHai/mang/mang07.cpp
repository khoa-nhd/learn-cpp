// Cho n
// Cho biết từ a1 đến an có các dãy liên tiếp thứ tự từ lớn đến nhỏ nào
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

void mang07(){
    int prev = a[0];
    cout<<prev<<" ";
    for(int i = 1; i < n; ++i){
        if(a[i-1]<=a[i]){
            cout<<a[i]<<" ";
        } else{
            cout<<"\n"<<a[i]<<" ";
        }
    }
}

int main(){
    freopen("MANG07.INP", "r", stdin);
    freopen("MANG07.OUT", "w", stdout);
    readData();
    mang07();
    return 0;
}

