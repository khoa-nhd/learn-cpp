#include <iostream>
#include <cstdio>
using namespace std;

void swap(int &a, int &b) {
    int m = a;
    a = b;
    b = m;
}

int main(){
    int a, b;
    cin >> a >> b;
    swap(a, b);
    cout << a << " " << b;
    return 0;
}
