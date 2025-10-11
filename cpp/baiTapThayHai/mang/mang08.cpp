// Cho n
// Cho biết từ a1 đến an có các dãy liên tiếp thứ tự từ lớn đến nhỏ dài nhất có độ dài bao nhiêu
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

int mang08(){
    int prev = a[0], longest = 0, length = 0;
    for(int i = 1; i < n; ++i){
        int temp = a[i], temp1 = a[i-1];
        if(a[i-1]<=a[i]){
            length += 1;
        } else{
            length = 0;
        }
        if(longest < length){
            longest = length;
        }
    }
    return longest;
}


int main(){
    freopen("MANG08.INP", "r", stdin);
    freopen("MANG08.OUT", "w", stdout);
    readData();
    int m;
    m = mang08();
    cout<<m+1;
    return 0;
}

