#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 10005

ll tongUoc[maxN] = {};

void sangtonguoc(){
    for(int i = 1; i < maxN; ++i){
        for(int j = i; j < maxN; j += i){
            tongUoc[j] += i;
        }
    }
}

ll findSumDivisors(ll n){
    ll sqrtn = sqrt(n);
    ll result = 0;
    for(int i = 1; i <= sqrtn; ++i){
        if(n % i == 0){
            if(i*i == n){
                result += tongUoc[i];
            } else{
                result += tongUoc[i];
                result += tongUoc[n/i];
            }
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;

    sangtonguoc();

    for(int i = 0; i < t; ++i){
        ll n;
        cin >> n;
        ll result;
        result = findSumDivisors(n);
        cout << result << "\n";
    }

    return 0;
}
