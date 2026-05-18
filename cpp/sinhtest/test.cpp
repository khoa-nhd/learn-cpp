#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

mt19937 rnt(777);

int rnd(int l, int r){
    return l + abs((int)rng) % (r - l + 1);
}

bool check(){
    return system("fc o.out o.ans") == 0;
}

void gen(){
    ofstream inp("i.inp");

    inp.close();
}

int main(){
    for(int i = 1; i <= 100; ++i){
        gen();
        system("task.exe");
        system("task_trau.exe");
        if(check()){
            cout << "Test: " << i << " AC\n";
        } else{
            cout << "Test: " << i << " WA\n";
            return 0;
        }
    }
    return 0;
}
