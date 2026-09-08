// Cho n, m
// Cho biết khi dịch trái mảng m lần thì mảng sẽ như thế nào
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define maxN 1000000

int a[maxN], b[maxN], n, m;

void readData(){
    cin>>n>>m;
    for(int i = 0; i < n; ++i){
        cin>>a[i];
    }
}

void printArray(){
    for(int i = 0; i < n; i++){
        cout<<b[i]<<" ";
    }
}
void mang10(){
    int soLanDich = m%n, j = 0;
    for(int i = soLanDich; i < n; ++i){
        b[j] = a[i];
        j += 1;
    }
    for(int i = 0; i<soLanDich; ++i){
        b[j] = a[i];
        j += 1;
    }
    printArray();
}

int main(){
    freopen("MANG10.INP", "r", stdin);
    freopen("MANG10.OUT", "w", stdout);
    readData();
    mang10();
    return 0;
}

