// Cho n
// Cho biết từ a1 đến an dãy đối xứng dài nhất có chiều dài bao nhiêu
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

int mang11(){
    int length = 1, longest = 0, j, k;
    for(int i = 1; i < n-1; ++i){
        length = 1;
        j = i-1;
        k = i+1;
        while(j>=0&&k<=n){
            if(a[j] == a[k]){
                length += 2;
            } else{
                break;
            }
            j -= 1;
            k += 1;
        }
        if(length > longest){
            longest = length;
        }
    }
    for(int i = 0; i < n-2; ++i){
        if(a[i] == a[i+1]){
            length = 2;
            k = i-1;
            j = i+2;
            while(j<=n&&k>=0){
                if(a[j] == a[k]){
                    length += 2;
                } else{
                    break;
                }
                j += 1;
                k -= 1;
            }
            if(length > longest){
                longest = length;
            }
        }
    }
    return longest;
}

int main(){
    freopen("MANG11.INP", "r", stdin);
    freopen("MANG11.OUT", "w", stdout);
    readData();
    int m;
    m = mang11();
    cout<<m;
    return 0;
}

