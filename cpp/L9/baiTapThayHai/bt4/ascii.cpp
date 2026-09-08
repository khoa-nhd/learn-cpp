#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string input[105];
ll w, h;

void readData(){
    cin >> h >> w;
    for(int i = 0; i < h; ++i){
        cin >> input[i];
    }
}

ll ascii(){
    ll result = 0;
    ll prev = -1;
    for(int i = 0; i < h; ++i){
        prev = -1;
        for(int j = 0; j < w; ++j){
            if(input[i][j] == '/' || input[i][j] == '\\'){
                if(prev == -1){
                    prev = j;
                } else{
                    result += j - prev;
                    prev = -1;
                }
            }
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ASCII.INP", "r", stdin);
    freopen("ASCII.OUT", "w", stdout);
    readData();
    ll result = ascii();
    cout << result;
    return 0;
}
