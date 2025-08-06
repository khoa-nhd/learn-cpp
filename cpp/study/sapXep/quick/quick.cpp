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
    cout << endl;
}

void quickSort(int a[], int n, int d, int c){
    int half = (d + c)/2;
    for(int i = 0; i<half; ++i){
        if(a[i]>a[half]){
            for(int j = n-1; j>=half; --j){
                if(a[j]<a[half]){
                    swap(a[i], a[j]);
                }
            }
        }
    }
    if(d < half){
        quickSort(a, n, d, half-1);
    }
    if(c > half){
        quickSort(a, n, half, c);
    }
}
int main() {
    int a[5] = {5, 3, 4, 1, 2}, n = 5;
    quickSort(a, n, 0, n-1);
    printArray(a, n);
    return 0;
}
