#include <cstdio>
#include <iostream>
using namespace std;

long long factorial(long long n){
    long long result = 1;
    for(int i = 1; i <= n; ++i){
        result *= i;
    }
    return result;
}

long long sumNum(long long n){
    long long result = 0;
    while(n>0){
        result += n%10;
        n /= 10;
    }
    return result;
}

long long functionn(long long n){
    if(n >= 6){
        return 9;
    }
    long long result, giaiThua;
    giaiThua = factorial(n);
    result = sumNum(giaiThua);
    return result;
}

int main(){
    freopen("FUNCTION.INP", "r", stdin);
    freopen("FUNCTION.OUT", "w", stdout);
    long long n, m;
    cin >> n;
    m = functionn(n);
    cout << m;
    return 0;
}
