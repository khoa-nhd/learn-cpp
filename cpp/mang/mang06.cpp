// Cho n
// Hãy xem từ a1 đến an vị trí của số nguyên tố lớn nhất
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

bool primeNumber(int n){
    if (n<=1){
        return false;
    }
    int m = sqrt(n);
    for(int i = 2; i <= m; ++i){
        if (n%i == 0){
            return false;
        }
    }
    return true;
}

int mang06(){
    int maxx = -1, pos = -1;
    for(int i = 0; i < n; ++i){
        if(primeNumber(a[i])){
            if(maxx == -1 || a[i] > maxx){
                maxx = a[i];
                pos = i;
            }
        }

    }
    return pos;
}

int main(){
    freopen("MANG06.INP", "r", stdin);
    freopen("MANG06.OUT", "w", stdout);
    readData();
    int maxx = mang06();
    if(maxx == -1){
        cout<<maxx;
    } else{
        cout<<maxx+1;
    }
    return 0;
}

