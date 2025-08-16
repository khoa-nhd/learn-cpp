#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

long long a[1000];
int n;

long long tichLonNhatPos(int id){
    long long maxx = -1, current = 0, pos = 0;
    for(int i = 0; i < n-1; ++i){
        current = a[i]*a[i+1];
        if(current > maxx && i != id && i != id+1){
            maxx = current;
            pos = i;
        }
    }
    return pos;
}

long long tich3chuSoLonNhatPos(){
    long long maxx = -1, current = 0, pos = 0;
    for(int i = 0; i < n-2; ++i){
        current = a[i]*a[i+1]*a[i+2];
        if(current > maxx){
            maxx = current;
            pos = i;
        }
    }
    return pos;
}

long long resultth1(int aa, int b, int c, int d){
    long long result = 0;
    for(int i = 0; i<n; ++i){
        if(i != aa && i != b && i != c && i != d){
            result = result + a[i];
        }
    }
    return result;
}

long long resultth2(int aa, int b, int c){
    long long result = 0;
    for(int i = 0; i<n; ++i){
        if(i != aa && i != b && i != c){
            result = result + a[i];
        }
    }
    return result;
}

long long maexp(){
    long long result = 0;
    long long biggestProductPos = tichLonNhatPos(-2);
    long long secondBiggestProductPos = tichLonNhatPos(biggestProductPos);
    long long biggest3numProductPos = tich3chuSoLonNhatPos();
    long long th1 = a[biggestProductPos] * a[biggestProductPos+1] + a[secondBiggestProductPos] * a[secondBiggestProductPos+1] + resultth1(biggestProductPos, biggestProductPos+1, secondBiggestProductPos, secondBiggestProductPos+1);
    long long th2 = a[biggest3numProductPos]*a[biggest3numProductPos+1]*a[biggest3numProductPos+2] + resultth2(biggest3numProductPos, biggest3numProductPos+1, biggest3numProductPos+2);
    result = max(th1, th2);
    return result;
}

int main(){
    freopen("MAEXP.INP", "r", stdin);
    freopen("MAEXP.OUT", "w", stdout);
    long long m;
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    m = maexp();
    cout<<m;
    return 0;
}
