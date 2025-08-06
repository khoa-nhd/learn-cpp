// Cho n
// Cho biết từ a1 đến an có các dãy liên tiếp số chính phương dài nhất có chiều dài bao nhiêu
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

bool squareNumber(int n){
    if(n<0){
        return false;
    }
    int m = sqrt(n);
    if(m*m == n){
        return true;
    }
    return false;
}

int mang09(){
    int prev = a[0], longest = 0, length = 0;
    for(int i = 0; i < n; ++i){
        if(squareNumber(a[i])){
            length += 1;
        } else{
            length = 0;
        }
        if(longest < length){
            longest = length;
        }
    }
    return longest;
}

int main(){
    freopen("MANG09.INP", "r", stdin);
    freopen("MANG09.OUT", "w", stdout);
    readData();
    int m;
    m = mang09();
    cout<<m;
    return 0;
}

