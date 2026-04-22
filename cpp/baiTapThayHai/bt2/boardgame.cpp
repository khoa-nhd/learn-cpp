#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

void et(string step, long long &cot, long long &hang){
    if(step == "ET" && cot < hang){
        cot += 1;
    }
}
void wt(string step, long long &cot, long long &hang){
    if(step == "WT" && cot > 1){
        cot -= 1;
    }
}
void ne(string step, long long &cot, long long &hang){
    if(step == "NE" && cot <= hang-1 && hang > 1){
        hang -= 1;
    }
}
void nw(string step, long long &cot, long long &hang){
    if(step == "NW" && cot > 1 && hang > 1){
        cot -= 1;
        hang -= 1;
    }
}
void sw(string step, long long &cot, long long &hang){
    if(step == "SW"){
        hang += 1;
    }
}
void se(string step, long long &cot, long long &hang){
    if(step == "SE"){
        cot += 1;
        hang += 1;
    }
}

long long boardgame(int n, string lenh){
    long long result = n;
    // tính vị trí ban đầu
    long long hang = 0, tongHang = 0;
    while (tongHang < n) {
        hang++;
        tongHang += hang;
    }
    long long cot = n - (tongHang - hang);

    long long current;
    string step;
    while(!lenh.empty()){
        step = lenh.substr(0, 2);
        lenh.erase(0, 2);
        long long hang1 = hang, cot1 = cot;
        et(step, cot, hang);
        wt(step, cot, hang);
        ne(step, cot, hang);
        nw(step, cot, hang);
        sw(step, cot, hang);
        se(step, cot, hang);
        if(hang != hang1 || cot != cot1){
            current = ((hang-1)*hang)/2 + cot;
            result += current;
        }

    }
    return result;
}

int main(){
    freopen("BOARDGAME.INP", "r", stdin);
    freopen("BOARDGAME.OUT", "w", stdout);
    string lenh;
    long long m, n;
    cin >> n >> lenh;
    m = boardgame(n, lenh);
    cout << m;
    return 0;
}
