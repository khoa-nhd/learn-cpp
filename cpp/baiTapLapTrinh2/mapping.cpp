#include <cstdio>
#include <iostream>
using namespace std;

void timToaDo(){
    long long hang = 0, cot = 0, target, tongCot = 0;
    cin >> target;
    while(tongCot < target){
        cot += 1;
        tongCot += cot;
    }
    if(tongCot == target){
        cout << 1 << " " << cot;
    } else{
        hang = tongCot - target + 1;
        cot = cot - (tongCot - target);
        cout << hang << " " << cot;
    }
}

void timGiaTri(){
    long long hang, cot;
    cin >> hang >> cot;
    long long result = 1;
    long long giaTriLon = ((hang + cot)*(hang + cot - 1))/2;
    result = giaTriLon - (hang - 1);
    cout << result << "\n";
}

int main(){
    freopen("MAPPING.INP", "r", stdin);
    freopen("MAPPING.OUT", "w", stdout);
    timGiaTri();
    timToaDo();
    return 0;
}
