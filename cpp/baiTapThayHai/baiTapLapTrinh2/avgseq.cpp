// Cho dãy B, tìm dãy A
// Dãy B là giá trị trung bình cộng của các phần tử của A tính từ đầu dãy
#include <iostream>
#include <cstdio>
using namespace std;
#define maxN 1000000

int a[maxN], b[maxN], n;

void readData(){
    cin>>n;
    for(int i = 0; i < n; ++i){
        cin>>b[i];
    }
}

void printArray(){
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
}

void avgseq(){
    long long prev;
    a[0] = b[0];
    prev = b[0];
    for(int i = 1; i<n; ++i){
        a[i] = b[i]*(i+1)-prev;
        prev += a[i];
    }
}

int main(){
    freopen("AVGSEQ.INP", "r", stdin);
    freopen("AVGSEQ.OUT", "w", stdout);
    readData();
    avgseq();
    printArray();
    return 0;
}
