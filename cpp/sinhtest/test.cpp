#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

mt19937 rng(777);

int rnd(int l, int r){
    return l + abs((int)rng() % (r - l + 1));
}

void gen(){
    ofstream inp("i.INP");
    ll len = rnd(2, 1e2);
    inp << rnd(1, 9);
    for(int i = 1; i < len; ++i) inp << rnd(0, 9);
    inp << " ";
    ll len2 = rnd(1, len-1);
    inp << rnd(1, 9);
    for(int i = 1; i < len2; ++i) inp << rnd(0, 9);
    inp.close();
}

bool check(){
    return system("fc o.out o.ans") == 0;
}

bool general_check(){
    ifstream inp("i.inp");
    ifstream out("o.out");
    ll a, b;
    inp >> a >> b;
    ll x, y, z, k;
    out >> x >> y >> z >> k;
//    cout << x << " " << y << " " << z << " " << k << "\n";
    inp.close();
    out.close();
    return(x == a + b &&
           y == a - b &&
           z == a * b &&
           k == a / b);
}

int main(){
    for(int i = 0; i <= 100; ++i){
        gen();
        system("task.exe");
        system("task_trau.exe");
        if(check()) cout << "test: " << i << " ac\n";
        else{
            cout << "test: " << i << " wa\n";
            return 0;
        }
    }
//    for(int i = 0; i <= 10000; ++i){
//        gen();
//        system("task.exe");
//        if(general_check()) cout << "test: " << i << " ac\n";
//        else{
//            cout << "test: " << i << " wa\n";
//            return 0;
//        }
//    }
    return 0;
}
