#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 3000005

ll tongUoc[maxN] = {};

void sangtonguoc(){
    for(int i = 1; i < maxN; ++i){
        for(int j = i + i; j < maxN; j += i){
            tongUoc[j] += i;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sangtonguoc();
    ll left, right;
    cin >> left >> right;

    ll result = 0;
    for(int i = left; i <= right; ++i){
        if(tongUoc[i] > i){
            result += 1;
        }
    }
    cout << result;

    return 0;
}
