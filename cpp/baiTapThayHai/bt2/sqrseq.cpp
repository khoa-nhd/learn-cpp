// Cho n
// Cho biết từ a1 đến an có các dãy liên tiếp số chính phương dài nhất có chiều dài bao nhiêu và xuất ra thứ tự phần tử đầu và cuối dãy
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

bool squareNumber(int n){
    if(n<=0){
        return false;
    }
    int m = sqrt(n);
    if(m*m == n){
        return true;
    }
    return false;
}

void sqrseq(){
    int prev = a[0], longest = 0, length = 0, lastPos = -1;
    for(int i = 0; i < n; ++i){
        if(squareNumber(a[i])){
            length += 1;
        } else{
            length = 0;
        }
        if(longest < length){
            longest = length;
            lastPos = i;

        }
    }
    if(longest == 0){
        cout<<0<<"\n";
        cout<<-1<<" "<<-1;
    } else {
        cout<<longest<<"\n";
        cout<<lastPos-(longest-1)+1<<" "<<lastPos+1;
    }
}

int main(){
    freopen("SQRSEQ.INP", "r", stdin);
    freopen("SQRSEQ.OUT", "w", stdout);
    readData();
    sqrseq();
    return 0;
}

