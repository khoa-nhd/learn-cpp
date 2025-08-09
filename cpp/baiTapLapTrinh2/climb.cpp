#include <iostream>
#include <cstdio>
#include <numeric>
using namespace std;
#define maxN 1000000

int a[maxN], n;

void readData(){
    cin>>n;
    for(int i = 0; i < n; ++i){
        cin>>a[i];
    }
}

long long climb(){
    long long start = 0, endd = 0, diff = 0, maxdif = 0;
    for(int i = 0; i<n; ++i){
        start = a[i];
        while(a[i]<a[i+1]){
            endd = a[i+1];
            i += 1;
        }
        diff = endd - start;
        if(diff > maxdif || maxdif == 0){
            maxdif = diff;
        }
    }
    return maxdif;
}

int main(){
    freopen("CLIMB.INP", "r", stdin);
    freopen("CLIMB.OUT", "w", stdout);
    long long m;
    readData();
    m = climb();
    cout<<m;
    return 0;
}


