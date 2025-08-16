#include <iostream>
#include <cstdio>
using namespace std;

int reversei(int n){
    int result = 0;
    while(n > 0){
        result = result*10 + n%10;
        n = n/10;
    }
    return result;
}

int gcd(int a, int b){
    int m = 0;
    int x = a, y = b;
    while(y != 0){
        m = x;
        x = y;
        y = m % y;
    }
    return x;
}

int numfre(int a, int b){
    int result = 0;
    for(int i = a; i <= b; ++i){
        if(gcd(i, reversei(i)) == 1){
            result += 1;
        }
    }
    return result;
}

int main(){
    freopen("NUMFRE.INP", "r", stdin);
    freopen("NUMFRE.OUT", "w", stdout);
    int a, b;
    cin >> a >> b;
    int m;
    m = numfre(a, b);
    cout << m;
    return 0;
}
