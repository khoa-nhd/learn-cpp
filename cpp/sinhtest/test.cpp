#include <bits/stdc++.h>
using namespace std;

mt19937 rng(7777);

int rnd(int l, int r){
    return l + abs((int)rng()) % (r - l + 1);
}

void gen(){
    ofstream inp("i.inp");
    int n = rnd(1, 1e3);
    int s = rnd(-1e9, 1e9);
    inp << n << " " << s << "\n";
    for(int i = 0; i < n; ++i){
        int a = rnd(-1e9, 1e9);
        inp << a << " ";
    }
    inp.close();
}

bool check(){
    return system("fc o.out o.ans") == 0;
}

int main(){
    for(int i = 1; i <= 10000; ++i){
        gen();
        system("task.exe");
        system("task_trau.exe");
        if(check()) cout << "test: " << i << " AC\n";
        else{
            cout << "test: " << i << " WA\n";
            return 0;
        }
    }
    return 0;
}
