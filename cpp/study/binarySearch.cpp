#include <bits/stdc++.h>
using namespace std;

int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int binarySearch(int d, int c, int target){
    if (d>c){
      return -1;
    }
    int half = (d+c)/2;
    if(a[half] == target){
        return half;
    }
    if(target < a[half]){
        return binarySearch(d, half-1, target);
    } else{
        return binarySearch(half+1, c, target);
    }
}

int main(){
    int n = 10;
    int m;
    m = binarySearch(0, n-1, 6);
    cout << m;
    return 0;
}
