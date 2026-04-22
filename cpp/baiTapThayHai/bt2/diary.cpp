#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int diary(int a, int b){
    int result = 0;
    if(a > 7){
        result = a-7;
    } else{
        result = b+7;
    }
    return result;
}

int main(){
    freopen("DIARY.INP", "r", stdin);
    freopen("DIARY.OUT", "w", stdout);
    int a, b, m;
    cin >> a >> b;
    m = diary(a, b);
    cout << m;
    return 0;
}
