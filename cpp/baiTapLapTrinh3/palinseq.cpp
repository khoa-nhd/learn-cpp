#include <bits/stdc++.h>
using namespace std;
#define maxN 1000000
typedef long long ll;

ll n, a[maxN];

void readData(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
}

ll palinseq(){
    ll i = 0, j = n-1;
    ll result = 0;
    ll bentrai = a[i], benphai = a[j];
    while(i < j){
        if(bentrai == benphai){
            i += 1;
            j -= 1;
            if(i <j){
                bentrai = a[i];
                benphai = a[j];
            }
        } else if(bentrai < benphai){
            i += 1;
            bentrai += a[i];
            result += 1;
        } else{
            j -= 1;
            benphai += a[j];
            result += 1;
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PALINSEQ.INP", "r", stdin);
    freopen("PALINSEQ.OUT", "w", stdout);
    readData();
    ll m;
    m = palinseq();
    cout << m;
    return 0;
}
