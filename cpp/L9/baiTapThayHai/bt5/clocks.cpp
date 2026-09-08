#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[10] = {};
ll soLuongPhepBD[9] = {};
ll soLanBD[10] = {};
ll phepBD[9][5] = {
    {1, 2, 4, 5, -1},
    {1, 2, 3, -1, -1},
    {2, 3, 5, 6, -1},
    {1, 4, 7, -1, -1},
    {2, 4, 5, 6, 8},
    {3, 6, 9, -1, -1},
    {4, 5, 7, 8, -1},
    {7, 8, 9, -1, -1},
    {5, 6, 8, 9, -1}
};
ll res[9] = {};
ll minMove = LLONG_MAX;

void readData(){
    for(int i = 1; i < 10; ++i){
        cin >> a[i];
    }
}

void capNhatRes(){
    bool hople = true;
    for(int i = 1; i < 10; ++i){
        if((a[i] + soLanBD[i]) % 4 != 0) hople = false;
    }
    if(hople){
        ll moveNum = 0;
        for(int i = 0; i < 9; ++i){
            moveNum += soLuongPhepBD[i];
        }
        if(moveNum < minMove){
            minMove = moveNum;
            for(int i = 0; i < 9; ++i){
                res[i] = soLuongPhepBD[i];
            }
        }
    }
}

void setPhepBD(int phep, int lan){
    for(int i = 0; i < 5; ++i){
        if(phepBD[phep][i] != -1){
            soLanBD[phepBD[phep][i]] += lan;
        }
    }
}

void setBD(){
    for(int i = 1; i < 10; ++i) soLanBD[i] = 0;
    for(int i = 0; i < 9; ++i){
        setPhepBD(i, soLuongPhepBD[i]);
    }
//    for(int i = 1; i < 10; ++i) cout << (soLanBD[i] + a[i]) % 4 << " ";
//    cout << "\n";
}

void clocks(ll pos){
    if(pos == 9){
        setBD();
        capNhatRes();
        return;
    }

    if(pos < 9){
        for(int i = 0; i <= 3; ++i){
            soLuongPhepBD[pos] = i;
            clocks(pos+1);
        }
    }
}

void outputRes(){
    if(minMove == LLONG_MAX){
        cout << "NO SOLUTION";
    } else{
        cout << minMove << "\n";
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < res[i]; ++j){
                cout << i + 1 << "\n";
            }
        }
    }
}

int main(){
    freopen("CLOCKS.INP", "r", stdin);
    freopen("CLOCKS.OUT", "w", stdout);
    readData();
    clocks(0);
    outputRes();
    return 0;
}
