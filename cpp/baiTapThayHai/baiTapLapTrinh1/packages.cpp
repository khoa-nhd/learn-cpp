// Cho n kg kẹo có loại túi 3kg và 5kg
// Cho biết cách cần ít túi nhất để đóng gói n kg kẹo
#include <iostream>
#include <cstdio>
using namespace std;

int packages(int n){
    int soGoi = -1, j = 0;
    for (int i = 0; i <= n/5; i++){
        if((n - i * 5) % 3 == 0 && (soGoi == -1 || soGoi > (n - i * 5)/3 + i)){
            j = (n - i*5)/3;
            soGoi = j+i;
        }
    }
    return soGoi;
}

int main(){
    freopen("PACKAGES.INP", "r", stdin);
    freopen("PACKAGES.OUT", "w", stdout);
    int n, m;
    cin>>n;
    m = packages(n);
    cout<<m;
    return 0;
}
