#include <cstdio>
#include <iostream>
using namespace std;
void swap(int &a, int &b) {
    int m = a;
    a = b;
    b = m;
}
void printArray(int a[], int n){
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
}
/*void selection(int a[], int n){
    int i = 0, j = 0, daSep = 0, minn, minPos;
    while(i<n){
        j = daSep;
        minn = a[daSep];
        minPos = daSep;
        while(j < n){
            if(a[j] < minn){
                minPos = j;
                minn = a[j];
            }
            j = j + 1;
        }
        swap(a[daSep], a[minPos]);
        daSep = daSep + 1;
        i = i + 1;
    }
    printArray(a, n);
}*/
void selection(int a[], int n){
    int i = 0, j = 0, daSep = 0, minn, minPos;
    for(int i = 0; i<n; i++){
        minn = a[daSep];
        minPos = daSep;
        for(j = daSep; j < n; j++){
            if(a[j] < minn){
                minPos = j;
                minn = a[j];
            }
        }
        swap(a[daSep], a[minPos]);
        daSep = daSep + 1;
    }
    printArray(a, n);
}
int main() {
    int a[5] = {5, 3, 4, 1, 2}, n = 5;
    selection(a, n);
    return 0;
}
