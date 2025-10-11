#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
string s;

void readData(){
    cin >> n >> s;
}

void crobot(){
    ll x = 0, y = 0;
    char huong = 'b';
    for(int i = 0; i < n; ++i){
        if(huong == 'b'){
            if(s[i] == 'G'){
                y += 1;
            } else if(s[i] == 'L'){
                x -= 1;
                huong = 't';
            } else if(s[i] == 'R'){
                x += 1;
                huong = 'd';
            } else{
                y -= 1;
                huong = 'n';
            }
        } else if(huong == 'n'){
            if(s[i] == 'G'){
                y -= 1;
            } else if(s[i] == 'L'){
                x += 1;
                huong = 'd';
            } else if(s[i] == 'R'){
                x -= 1;
                huong = 't';
            } else{
                y += 1;
                huong = 'b';
            }
        } else if(huong == 'd'){
            if(s[i] == 'G'){
                x += 1;
            } else if(s[i] == 'L'){
                y += 1;
                huong = 'b';
            } else if(s[i] == 'R'){
                y -= 1;
                huong = 'n';
            } else{
                x -= 1;
                huong = 't';
            }
        } else{
            if(s[i] == 'G'){
                x -= 1;
            } else if(s[i] == 'L'){
                y -= 1;
                huong = 'n';
            } else if(s[i] == 'R'){
                y += 1;
                huong = 'b';
            } else{
                x += 1;
                huong = 'd';
            }
        }
    }
    cout << x << " " << y;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CROBOT.INP", "r", stdin);
    freopen("CROBOT.OUT", "w", stdout);
    readData();
    crobot();
    return 0;
}
