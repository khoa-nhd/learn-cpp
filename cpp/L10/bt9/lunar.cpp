#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string can[] = {"GIAP", "AT", "BINH", "DINH", "MAU", "KY", "CANH", "TAN", "NHAM", "QUY"};
string chi[] = {"TI", "SUU", "DAN", "MAO", "THIN", "TY", "NGO", "MUI", "THAN", "DAU", "TUAT", "HOI"};
ll bdca = 7;
ll bdch = 9;

ll n;
string s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("LUNAR.INP", "r", stdin);
    freopen("LUNAR.OUT", "w", stdout);
    cin >> n >> s;
    ll mindiff = 1e18;
    ll minval = -1;
    for(int i = 1; i <= 10005; ++i){
        if(can[bdca] == s || chi[bdch] == s){
            if(mindiff > abs(n - i)){
                mindiff = abs(n - i);
                minval = i;
            }
        }
        bdca += 1;
        bdca %= 10;
        bdch += 1;
        bdch %= 12;
    }
    cout << minval;
    return 0;
}
