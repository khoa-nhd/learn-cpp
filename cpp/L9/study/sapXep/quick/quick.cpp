#include <cstdio>
#include <iostream>
using namespace std;

int a[10] = {5, 2, 4, 1, 3, 7, 9, 8, 6, 10};

void swap(int &a, int &b) {
    int m = a;
    a = b;
    b = m;
}
void printArray(int n){
    for(int i = 0; i < n; i++){
        cout<<a[i]<<" ";
    }
}

void quickSort(int d, int c){
    if(d < c){
        int i = d-1, j = d;
        while(j <= c){
            if(a[j] <= a[c]){
                i += 1;
                if(a[i] > a[j] || j == c){
                    swap(a[i], a[j]);
                }
            }
            j += 1;
        }
        quickSort(d, i - 1);
        quickSort(i + 1, c);
    }
}

int main() {
    int n = 10;
    quickSort(0, n-1);
    printArray(n);
    return 0;
}
