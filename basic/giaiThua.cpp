#include <iostream>

using namespace std;
long tinhGiaTri(int n){
    int i = 1;
    long giaiThua = 1;
    while (i <= n){
        giaiThua = giaiThua * i;
        i = i + 1;
    }
    return giaiThua;
}

long tinhGiaiThua (int n){
    long giaiThua = 1;
    int i = i + 1;
    while (i <= n-1) {
        giaiThua = giaiThua * i;
        i++;
    }
    giaiThua *= n;
    return giaiThua;
}

int main(){
    int n;
    cin >> n;
    long m = tinhGiaiThua(n);
    cout<<m;
}
