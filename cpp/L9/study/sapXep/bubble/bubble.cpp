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
/*void bubble(int a[], int n){
    int i = 0, j = 0, b = n-1;
    while(j <= n-1){
        i = 0;
        while(i < b){
            if (a[i] > a[i+1]){
                swap(a[i], a[i+1]);
            }
            i = i + 1;
        }
        b = b - 1;
        j = j + 1;
    }
    printArray(a, n);
}*/
void bubble(int a[], int n){
    int i = 0, j = 0, b = n-1;
    for(j = 0; j <= n-1; j++){
        for(i = 0; i < b; i++){
            if (a[i] > a[i+1]){
                swap(a[i], a[i+1]);
            }
        }
        b = b - 1;
    }
    printArray(a, n);
}
int main() {
    int a[5] = {5, 3, 4, 1, 2}, n = 5;
    bubble(a, n);
    return 0;
}
