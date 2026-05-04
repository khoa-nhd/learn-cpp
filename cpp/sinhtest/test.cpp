#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

mt19937 rng(16);
const int test = 100;

ll rnd(ll l, ll r){
    return l + (abs((ll)rng() % (r-l+1)));
}

void gen(){
    ofstream inp("i.inp");
    ll a, b;
    a = rnd(1, 1e10);
    b = rnd(1, 1e10);
    inp << a << " " << b;
    inp.close();
}

bool check(){
    if(system("fc o.out o.ans") != 0){
        return false;
    }
    return true;
}

int main(){
    for(int i = 1; i <= test; ++i){
        gen();
        system("task.exe");
        system("task_trau.exe");
        bool ok = check();
        cout << "test: " << i;
        if(ok) cout << " AC\n";
        else{
            cout << " WA\n";
//            return 0;
        }
    }
    return 0;
}
